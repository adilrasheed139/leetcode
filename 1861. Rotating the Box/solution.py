class Solution:
    def rotateTheBox(self, box: List[List[str]]) -> List[List[str]]:
        # Simulate falling stones row by row
        for row in box:
            empty = len(row) - 1  # The position where the next stone can "fall"
            for col in range(len(row) - 1, -1, -1):
                if row[col] == '*':  # Obstacle
                    empty = col - 1
                elif row[col] == '#':  # Stone
                    row[col], row[empty] = row[empty], row[col]
                    empty -= 1

        # Rotate the box by 90 degrees clockwise
        m, n = len(box), len(box[0])
        rotated_box = [[None] * m for _ in range(n)]
        for i in range(m):
            for j in range(n):
                rotated_box[j][m - 1 - i] = box[i][j]

        return rotated_box
