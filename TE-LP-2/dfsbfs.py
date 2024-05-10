from collections import defaultdict, deque

class Graph:
    def __init__(self):
        self.graph = defaultdict(list)

    def add_node(self, nodeVal):
        if nodeVal not in self.graph:
            self.graph[nodeVal] = []

    def add_edge(self, u, v):
        self.graph[u].append(v)
        self.graph[v].append(u)

    def dfs(self, start, end, path=[], level=0):
        path = path + [start]
        print(f"Node {start} at level {level}")

        if start == end:
            return path

        for neighbour in self.graph[start]:
            if neighbour not in path:
                new_path = self.dfs(neighbour, end, path, level + 1)
                if new_path:
                    return new_path

        return None

    def bfs(self, start, end):
        queue = deque([(start, [start])])
        levels = {start: 0}

        while queue:
            current, path = queue.popleft()
            level = levels[current]
            print(f"Node {current} at level {level}")

            for neighbour in self.graph[current]:
                if neighbour not in path:
                    new_path = path + [neighbour]
                    levels[neighbour] = level + 1
                    if neighbour == end:
                        return new_path, levels
                    else:
                        queue.append((neighbour, new_path))
        return None, None

    def display_graph(self):
        print("Current State of Graph: ")
        for node, neighbours in self.graph.items():
            print(f"\nNode {node} connects to: {neighbours}")


# Driver Code
network = Graph()

nodeNo = int(input("Enter the Number of Nodes: "))

for _ in range(nodeNo):
    nodeVal = int(input("Enter the Value of Node: "))
    network.add_node(nodeVal)

edgeNo = int(input("Enter the Number of Edges: "))

for _ in range(edgeNo):
    u, v = map(int, input("Enter the Edge (u v): ").split())
    network.add_edge(u, v)

start = int(input("Enter the Start Node: "))
end = int(input("Enter the End Node: "))

if start in network.graph and end in network.graph:
    dfs_path = network.dfs(start, end)
    print("DFS Path: ", dfs_path)

if start in network.graph and end in network.graph:
    bfs_path, levels = network.bfs(start, end)
    print("BFS Path: ", bfs_path)

network.display_graph()
