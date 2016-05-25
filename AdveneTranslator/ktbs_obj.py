from collections import OrderedDict
import json
import requests
import random
import string

class Base:
    def __init__(self, _id, root_url, label):
        self.id = _id
        self.root_url = root_url
        self.url = root_url + _id
        self.label = label

    def recreate(self):
        print("recreating", self.url)
        self.delete()
        self.send()

    def to_json(self):
        d = OrderedDict()
        d["@id"] = self.id
        d["@type"] = "Base"
        d["label"] = self.label
        return d
        # return  {"@id": self.id, "@type": "Base", "label": self.label}

    def send(self):
        post_data = json.dumps(self.to_json(), sort_keys=True, indent=4, separators=(',', ': '))
        print(post_data)
        # r = requests.get(url)
        # print(r.status_code)
        # print(r.headers)

        requests.post(self.root_url, json=self.to_json(), headers={'content-type': 'application/json'})

    def delete(self):
        print("deleting", self.url)
        r = requests.delete(self.url)
        if r.status_code == 409:
            print("Traces présentes dans la base. Nettoyage...")
            r = requests.get(self.url)
            j = r.json()
            for t in j['contains']:
                print("nettoyage de", t['@id'])
                tr = StoredTrace(t['@id'][2:], '', self)
                tr.delete()

def getRandomString():
    return ''.join(random.choice(string.ascii_letters + string.digits) for i in range(10))

class StoredTrace:
    def __init__(self, _id, model, base, origin=getRandomString()):
        assert isinstance(base, Base)
        self.id = _id
        self.model = model
        self.base = base
        self.root_url = base.root_url
        self.url = base.url + _id
        self.type = "StoredTrace"
        self.origin = origin
        self.obsels = list()

    def to_json(self):
        d = OrderedDict()
        d["@id"] = self.id
        d["@type"] = self.type
        d["hasModel"] = self.model
        d["origin"] = self.origin
        return d

    def send(self, root_url="http://127.0.0.1:8001/"):
        url = self.base.url

        post_data = json.dumps(self.to_json(), sort_keys=True, indent=4, separators=(',', ': '))
        # print(post_data)
        # r = requests.get(url)
        r = requests.post(url, json=self.to_json(), headers={'content-type': 'application/json'})
        if r.status_code - r.status_code % 100 != 200:
            print("trace send return status :", r.status_code)

    def delete(self, root_url="http://127.0.0.1:8001/"):
        r = requests.delete(self.url)
        if r.status_code - r.status_code % 100 != 200:
            print("trace delete return status :", r.status_code)

    def add_obsel(self, obsel, immediate_request=True):
        self.obsels.append(obsel)

    def send_obsel(self, obsel):
        print("sending obsel", json.dumps(obsel), "to url:", self.url)

        requests.post(self.url, json=obsel, headers={'content-type': 'application/json'})


#TODO intégrer ça au reste
class Obsel:
    def __init__(self,id:str,start:int,end:int,type:str):
        self.id = id
        self.start = start
        self.end = end
        self.type = type

    def __str__(self):
        return "{id: "+ self.id +", start:"+ self.start +", end:"+ self.end +", type:\""+ self.type +"\"}"

#requests.post("http://192.168.1.130:8001/base1/t01/", json={"@id": "obs1", "@type": "m:SimpleObsel"})