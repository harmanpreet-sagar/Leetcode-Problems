class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        longest = 0
        last_idx = 0

        past_chars = {}

        curr_length = 0

        if s:
            for i in range(len(s)):
                print(f"Current String: {s[i]}")
                
                if s[i] not in past_chars:
                    curr_length += 1
                    print(f"I AM HERE and the length: {curr_length}")
                    past_chars[s[i]] = 1
                else:
                    curr_length = 0
                    print(f"I AM THERE and the length: {curr_length}")
                    print(f"Past chars: {past_chars}")
                    if past_chars:
                        past_chars.clear()
                
                if curr_length > longest:
                    longest = curr_length
        
        return longest

        