from AdveneTranslator.ktbs_obj import Obsel
from xml.etree import ElementTree


def handle_advene_xml(file="first_test.xml"):
    ns = {"m": "http://experience.univ-lyon1.fr/advene/ns"}

    tree = ElementTree.parse(file)
    root = tree.getroot()

    #for child in root:
    #    print(child.tag, child.attrib)
    annotations = list()
    relations = list()

    annotationsNode = list(root.iterfind("m:annotations",ns))[0]
    print(annotationsNode)
    for a in annotationsNode:
        if a.tag.endswith("annotation"):
            #print(a[0].get("begin"))
            o = Obsel(a.get("id"), a[0].get("begin"), a[0].get("end"), a[1].text)
            print(o)
            annotations.append(o)
        elif a.tag.endswith("relation"):
            pass

handle_advene_xml()