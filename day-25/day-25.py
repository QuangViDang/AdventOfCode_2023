import math
import networkx


def _parse_input(in_str: str):
    res = networkx.Graph()
    for cur_line in in_str.splitlines():
        start, nodes = cur_line.split(": ")
        for _ in nodes.split(" "):
            res.add_edge(start, _)
    return res


def solve_a(in_str: str) -> int:
    """returns the solution for part_a"""
    graph = _parse_input(in_str)
    edges_to_remove = networkx.minimum_edge_cut(graph)
    graph.remove_edges_from(edges_to_remove)
    components = list(networkx.connected_components(graph))
    return math.prod(len(_) for _ in components)


def main():
    with open("input.txt", "r") as file:
        input_data = file.read()

    result_part_a = solve_a(input_data)
    print(f"Result: {result_part_a}")


if __name__ == "__main__":
    main()
