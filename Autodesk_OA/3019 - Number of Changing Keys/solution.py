class Solution:
    def countKeyChanges(self, s: str) -> int:
        new_str = s.lower()
        change = 0

        for i in range(len(new_str)):
            if i == 0:
                continue
            else:
                if new_str[i-1] != new_str[i]:
                    change += 1

        return change
        