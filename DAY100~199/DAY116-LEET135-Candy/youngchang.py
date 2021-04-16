class Solution:
    def candy(self, ratings) -> int:
        ramps = []
        
        st = ed = 0
        hill = dale = False
        length = 1
        for i in range(1, len(ratings)):
            if ratings[i] > ratings[i - 1]:
                if dale:
                    if length >= 2:
                        ramps.append((length, st, ed, 'dale'))
                    st = i - 1
                    ed = i
                    length = 2
                elif hill:
                    ed = i
                    length += 1
                else:
                    st = i - 1
                    ed = i
                    length = 2
                dale = False
                hill = True
            elif ratings[i] < ratings[i - 1]:
                if hill:
                    if length >= 2:
                        ramps.append((length, st, ed, 'hill'))
                    st = i - 1
                    ed = i
                    length = 2
                elif dale:
                    ed = i
                    length += 1
                else:
                    st = i - 1
                    ed = i
                    length = 2
                dale = True
                hill = False
            else:
                if length >= 2:
                    if dale:
                        ramps.append((length, st, ed, 'dale'))
                    else:
                        ramps.append((length, st, ed, 'hill'))
                dale = False
                hill = False
                length = 1
                st = i
                ed = i
        if length >= 2:
            if dale:
                ramps.append((length, st, ed, 'dale'))
            else:
                ramps.append((length, st, ed, 'hill'))
        
        ramps.sort(reverse = True)

        candy = [1] * len(ratings)
        for length, st, ed, ramp in ramps:
            if ramp == 'hill':
                val = 1
                for i in range(st, ed + 1):
                    candy[i] = max(candy[i], val)
                    val += 1
            else:
                val = 1
                for i in range(ed, st - 1, -1):
                    candy[i] = max(candy[i], val)
                    val += 1
        

        return sum(candy)