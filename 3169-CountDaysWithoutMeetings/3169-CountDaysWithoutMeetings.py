# Last updated: 3/24/2025, 10:22:49 AM
class Solution:
    def countDays(self, days: int, meetings: List[List[int]]) -> int:
        busy_days = 0
        meetings.sort(key=lambda x: x[0])
        start = meetings[0][0]
        end = meetings[0][1]
        for i in range(1, len(meetings)):
            curr_start = meetings[i][0]
            curr_end = meetings[i][1]
            if curr_start <= end:
                end = max(end, curr_end)
            else:
                busy_days += end - start + 1
                start = curr_start
                end = curr_end
        busy_days += end - start + 1
        return days - busy_days