def solution(people, limit):
    people.sort()
    length = len(people)
    two_in_boat = 0
    front_cursor = 0
    back_cursor = length-1
    while True:
        if front_cursor >= back_cursor:
            break
        if people[front_cursor] + people[back_cursor] <= limit:
            front_cursor += 1
            back_cursor -= 1
            two_in_boat += 1
        else:
            back_cursor -= 1

    return length-two_in_boat