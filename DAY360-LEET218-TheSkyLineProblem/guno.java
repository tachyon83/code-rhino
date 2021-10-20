import java.util.*;

class Solution {

    static class Point{
        int x,h;
        boolean isLeft;

        public Point(int x, int h, boolean isLeft) {
            this.x = x;
            this.h = h;
            this.isLeft = isLeft;
        }
    }
    static public List<List<Integer>> getSkyline(int[][] buildings) {
        List<Point> list = new ArrayList<>();
        List<List<Integer>> ret = new ArrayList<>();
        for (int[] building : buildings) {
            list.add(new Point(building[0], building[2], true));
            list.add(new Point(building[1], building[2], false));
        }
        list.sort((o1, o2) -> {
            if(o1.x==o2.x){
                if(!o1.isLeft && o2.isLeft) // 오른쪽 포인트를 나중에 정렬
                    return 1;
                else if(o1.isLeft && !o2.isLeft) // 오른쪽 포인트를 나중에 정렬
                    return -1;
                else if(o1.isLeft && o2.isLeft) // 둘다 왼쪽이면 내림차순
                    return o2.h - o1.h;
                else if(!o1.isLeft && !o2.isLeft) // 둘다 왼쪽이면 오름차순
                    return o1.h - o2.h;
                else
                    return 0;
            }else {
                return o1.x - o2.x;
            }
        });

        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        pq.add(0);
        int max = 0;
        for (Point point : list) {
            if(point.isLeft)
                pq.add(point.h);
            else
                pq.remove(point.h);
            if (max != pq.peek()) {
               max = pq.peek();
                ret.add(List.of(point.x, max));
            }

        }
        return ret;
    }


}
