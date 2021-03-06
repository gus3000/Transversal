import json
from collections import OrderedDict
from AdveneTranslator.ktbs_obj import StoredTrace, Base


def extract_keys(obsels, keys):
    """

    :rtype: OrderedDict
    """
    d = OrderedDict()

    for k in keys:
        val = obsels[k]

        if k == "id" or k == "type":
            d["@" + k] = val
        elif k == "begin" or k == "end":
            d[k] = val
        else:
            d["m:" + k] = val

    return d

root_url = "http://192.168.1.197:8001/"
b = Base("base1/", root_url, "test python base")
# b.delete()
b.recreate()

t = StoredTrace("observations/", root_url + "base1/model1/", b)
print(json.dumps(t.to_json(), indent=4, separators=[',', ': ']))
t.send(root_url)

with open('v2.json', 'r') as f1, open('trace.json', 'w') as f2:
        tab = json.load(f1)
        #print(tab)
        for obs in tab['annotations']:
            #print(obs)
            #obsel = OrderedDict([('id',obs['id']), \
            #('type',obs['type']),('begin',obs['begin']),('end',obs['end']),('content',obs['content'])])
            obsel = extract_keys(obs, ['id', 'type', 'begin', 'end', 'content'])
            #trace.append(obsel)
            t.add_obsel(obsel)
            t.send_obsel(obsel)

            # order : id,type,begin,end,others
            #json.dump(trace, f2, sort_keys=False, indent=4, separators=[',',': '])
            #print(json.dumps(trace, sort_keys=False, indent=4, separators=[',',': ']))
