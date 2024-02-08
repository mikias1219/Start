import itertools

def traveling_salesperson(cost_matrix):
    cities = list(range(len(cost_matrix)))
    min_cost = float('inf')
    min_path = None

    for path in itertools.permutations(cities):
        path_cost = calculate_path_cost(path, cost_matrix)
        if path_cost < min_cost:
            min_cost = path_cost
            min_path = path

    return min_path, min_cost

def calculate_path_cost(path, cost_matrix):
    cost = 0
    for i in range(len(path) - 1):
        cost += cost_matrix[path[i]][path[i + 1]]
    cost += cost_matrix[path[-1]][path[0]]  # Return to the starting city
    return cost

# Example cost matrix
cost_matrix = [
    [0, 10, 15, 20, 25],
    [10, 0, 35, 25, 30],
    [15, 35, 0, 30, 20],
    [20, 25, 30, 0, 10],
    [25, 30, 20, 10, 0]
]

min_path, min_cost = traveling_salesperson(cost_matrix)

print(f"Optimal tour order: {min_path}")
print(f"Minimum cost: {min_cost}")
