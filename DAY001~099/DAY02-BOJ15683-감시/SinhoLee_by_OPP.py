'''
괜히 뻘짓한거 같네요 cctv_1 ~5 까지 중복코드를 없애고 싶어서
클래스형식으로 구현하고, getattr함수 써서 중복은 피했지만 전체적인 코드량은 두배
가까이 증가... 채첨시간도 두배넘게 증가..
이왕 시도한김에 opp원칙에 최대한 근접하게 하고싶었는데 이미 너무 이 문제에 대한 
솔루션에만 강결함상태인것같고.... 사실 뭐가 뭔지 잘 모르겠습니다.
일반적인 풀이랑 로직은 똑같은데 두배가 더 걸리는 이유 아시는분 코멘트 부탁드려요...
'''
class Cctv:
    dy = [-1, 0, 1, 0]
    dx = [0, 1, 0, -1]

    def __init__(self, n, m):
        self.n = n
        self.m = m
        self.mat = []
        self.cctv_list = []
        for _ in range(self.n):
            temp = list(map(int, input().split()))
            self.mat.append(temp)

        for i in range(n):
            for j in range(m):
                if 1 <= self._get_mat()[i][j] < 6:
                    self.cctv_list.append((i, j))

    def _get_n(self):
        return self.n

    def _get_m(self):
        return self.m

    def _get_cctv_list(self):
        return self.cctv_list

    def _get_dy(self):
        return self.dy

    def _get_dx(self):
        return self.dx

    def _get_mat(self):
        return self.mat

    def _get_ny_nx_from_d_y_x(self, d, y, x):
        dd = d % 4  # adjust
        return y+self._get_dy()[dd], x+self._get_dx()[dd]

    def _is_out_of_bound(self, ny, nx):
        return not (0 <= ny < self._get_n() and 0 <= nx < self._get_m())

    def _fill(self, d, y, x, deep_copied_mat):
        '''
        :param d: 방향
        :param x: cctv x좌표
        :param y: cctv y좌표
        :param deep_copied_mat: cctv 전체공간을 deepcopy한 매트릭스
        :return: 감시공간을 채운 뒤의 매트릭스
        '''
        while True:
            ny, nx = self._get_ny_nx_from_d_y_x(d, y, x)
            if self._is_out_of_bound(ny, nx):
                break
            if deep_copied_mat[ny][nx] == 6:
                break
            if deep_copied_mat[ny][nx] == 0:
                deep_copied_mat[ny][nx] = 9
            y, x = ny, nx

        return deep_copied_mat

    def _cctv_1(self, d, y, x, deep_copied_mat):
        return self._fill(d, y, x, deep_copied_mat)

    def _cctv_2(self, d, y, x, deep_copied_mat):
        deep_copied_mat = self._fill(d, y, x, deep_copied_mat)
        deep_copied_mat = self._fill(d + 2, y, x, deep_copied_mat)
        return deep_copied_mat

    def _cctv_3(self, d, y, x, deep_copied_mat):
        deep_copied_mat = self._fill(d, y, x, deep_copied_mat)
        deep_copied_mat = self._fill(d + 1, y, x, deep_copied_mat)
        return deep_copied_mat

    def _cctv_4(self, d, y, x, deep_copied_mat):
        deep_copied_mat = self._fill(d, y, x, deep_copied_mat)
        deep_copied_mat = self._fill(d + 1, y, x, deep_copied_mat)
        deep_copied_mat = self._fill(d + 2, y, x, deep_copied_mat)
        return deep_copied_mat

    def _cctv_5(self, d, y, x, deep_copied_mat):
        deep_copied_mat = self._fill(d, y, x, deep_copied_mat)
        deep_copied_mat = self._fill(d + 1, y, x, deep_copied_mat)
        deep_copied_mat = self._fill(d + 2, y, x, deep_copied_mat)
        deep_copied_mat = self._fill(d + 3, y, x, deep_copied_mat)
        return deep_copied_mat

    def _cnt_zero(self, mat):
        return sum(1 if mat[i][j] == 0 else 0 for j in range(self._get_m()) for i in range(self._get_n()))

    # interface 역할을 하기 위해 클래스 형식으로 구현함.
    # if cctv_mun ==1, 2, 3, 4, 5 마다 구분하는 반복을 없애기 위해 getattr(instance, method_name)구조를 사용
    # 아니 근데 왜 시간이 두배나 더 걸리는거지? ㅜㅠ
    def _cctv(self, d, y, x, cctv_num, mat):
        deep_copied_mat = self._get_deep_copied_mat(mat)
        func_prefix = '_cctv_'
        handler_method = func_prefix + str(cctv_num)
        handler = getattr(self, handler_method)
        deep_copied_mat = handler(d, y, x, deep_copied_mat)
        return deep_copied_mat

    def _perm(self, depth, mat, min_res):
        if depth == -1:
            return min(min_res, self._cnt_zero(mat))

        for d in range(4):
            y, x = self._get_cctv_list()[depth][0], self._get_cctv_list()[depth][1]
            cctv_num = mat[y][x]
            min_res = min(min_res, self._perm(depth-1, self._cctv(d, y, x, cctv_num, mat), min_res))
        return min_res

    def _get_deep_copied_mat(self, mat):
        return [arr[:] for arr in mat]

    def get_answer(self):
        return self._perm(len(self._get_cctv_list())-1, self._get_mat(), 64)


n, m = map(int, input().split())
cctv = Cctv(n, m)
print(cctv.get_answer())
del cctv

