import json
from ktbs_obj import Base, StoredTrace
from collections import OrderedDict


def extract_keys(obsels, keys):
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


b = Base("base1/", "test python base")
# b.delete()
b.recreate()

t = StoredTrace("t01/", "http://192.168.1.130:8001/base1/model1/", b)
print(json.dumps(t.to_json(), indent=4, separators=[',', ': ']))
t.send()

with open('v2.json', 'r') as f1:
    with open('trace.json', 'w') as f2:
        tab = json.load(f1)
        # print(tab)
        for obs in tab['annotations']:
            # print(obs)
            # obsel = OrderedDict([('id',obs['id']), \
            # ('type',obs['type']),('begin',obs['begin']),('end',obs['end']),('content',obs['content'])])
            obsel = extract_keys(obs, ['id', 'type', 'begin', 'end', 'content'])
            #trace.append(obsel)
            t.add_obsel(obsel)
            t.send_obsel(obsel)

            # order : id,type,begin,end,others
            # json.dump(trace, f2, sort_keys=False, indent=4, separators=[',',': '])
            # print(json.dumps(trace, sort_keys=False, indent=4, separators=[',',': ']))
