from collections import defaultdict, deque
from typing import List

class Solution:
    def validArrangement(self, pairs: List[List[int]]) -> List[List[int]]:
        # Step 1: Build the graph and track in-degrees and out-degrees
        graph = defaultdict(deque)
        in_degree = defaultdict(int)
        out_degree = defaultdict(int)
        
        for u, v in pairs:
            graph[u].append(v)
            out_degree[u] += 1
            in_degree[v] += 1
        
        # Step 2: Find the starting node
        start = pairs[0][0]  # Default start node
        for node in graph:
            if out_degree[node] > in_degree[node]:
                start = node
                break

        # Step 3: Perform Hierholzer's algorithm
        result = []
        stack = [start]
        
        while stack:
            while graph[stack[-1]]:
                stack.append(graph[stack[-1]].popleft())
            result.append(stack.pop())
        
        # Step 4: Reverse the result and form the valid arrangement
        result.reverse()
        return [[result[i], result[i + 1]] for i in range(len(result) - 1)]
