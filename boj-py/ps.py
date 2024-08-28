def min_commands_to_paint_fence(n, fence):
    # 필요한 '#'의 위치를 찾습니다.
    positions = [i for i in range(n) if fence[i] == '#']
    # '#'가 없다면 모든 i에 대해 0을 출력
    if not positions:
        print(' '.join(['0'] * n))
        return

    result = []

    for i in range(1, n + 1):
        possible = True
        commands = 0
        start = 0

        while start < len(positions):
            end = start
            # i마리의 나무늘보가 커버할 수 있는 최대 범위 찾기
            while end < len(positions) and positions[end] - positions[start] < i:
                end += 1

            if end == start:  # 커버할 수 없는 경우
                possible = False
                break

            # 다음 시작점으로 이동
            start = end
            commands += 1

        if possible:
            result.append(str(commands))
        else:
            result.append('-1')

    print(' '.join(result))


# 입력 예시
n = int(input())
fence = input().strip()

# 결과 출력
min_commands_to_paint_fence(n, fence)
