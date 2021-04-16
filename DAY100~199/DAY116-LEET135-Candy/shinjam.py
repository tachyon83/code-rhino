class Solution:
    def candy(self, ratings: List[int]) -> int:
        N = len(ratings)
        status = [1] * N
        queue = sorted(enumerate(ratings), key=lambda x: x[1])
        for idx, rating in queue:
            for v in idx - 1, idx + 1:
                if not 0 <= v < N:
                    continue
                # 좌우 갱신
                if ratings[v] > rating:
                    status[v] = max(status[v], status[idx] + 1)

        return sum(status)
