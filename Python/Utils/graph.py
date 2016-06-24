from graphviz import Digraph

class Graph:
    def __init__(self, name: str = ''):
        """
        :type name: str
        """
        assert isinstance(name, str)
        self.name = name


class Node:
    node_id = 0

    def __init__(self):
        self.__id = Node.node_id
        Node.node_id += 1

    #Built-in overloads
    def __str__(self):
        return 'Node ' + str(self.__id)
    def __eq__(self, other):
        if not(isinstance(other, Node)):
            return False
        return self.__id == other.__id

class Edge:
    def __init__(self, start: Node, end: Node, flowId: int = 0):
        self.__start = start
        self.__end = end
        self.__flowId = flowId


    @property
    def start(self) -> Node:
        return self.__start

    @property
    def end(self) -> Node:
        return self.__end
