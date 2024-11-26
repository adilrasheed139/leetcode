from collections import defaultdict, deque

class Solution:
    def findChampion(self, n: int, edges: List[List[int]]) -> int:
        # Build graph and compute in-degree
        graph = defaultdict(list)
        in_degree = [0] * n
        
        for u, v in edges:
            graph[u].append(v)
            in_degree[v] += 1
        
        # Collect nodes with 0 in-degree
        zero_in_degree = [i for i in range(n) if in_degree[i] == 0]
        
        if len(zero_in_degree) != 1:
            return -1  # More than one or no candidate for champion
        
        # Candidate for champion
        champion = zero_in_degree[0]
        
        # Verify if the champion can reach all other nodes
        visited = set()
        
        def dfs(node):
            if node in visited:
                return
            visited.add(node)
            for neighbor in graph[node]:
                dfs(neighbor)
        
        dfs(champion)
        
        if len(visited) != n:
            return -1  # Champion does not dominate all teams
        
        return champion
