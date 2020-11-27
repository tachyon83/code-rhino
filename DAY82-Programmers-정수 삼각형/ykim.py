def solution(triangle):

  # 첫째 줄은 index가 0이므로, 둘째 줄부터 계산한다.
  for rows in range(1, len(triangle)):

    # 각 줄의 index 값별로 비교한다.
    for idx in range(rows + 1):

      # 가장 왼쪽 값인 경우
      if idx == 0:
        triangle[rows][idx] += triangle[rows-1][idx]
      
      # 가장 오른쪽 값인 경우
      elif idx == rows:
        triangle[rows][idx] += triangle[rows-1][-1]
      
      else:
        triangle[rows][idx] += max(triangle[rows-1][idx-1], triangle[rows-1][idx])
  
  # 가장 마지막 줄의 최댓값을 구하면 된다.
  return max(triangle[-1])
