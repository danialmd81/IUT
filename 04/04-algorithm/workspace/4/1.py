def permute(s, left, final_solution):
    if left == len(s) - 1:
        final_solution.append("".join(s))
        return
    i = left
    while i < len(s):
        s[left], s[i] = s[i], s[left]
        permute(s, left + 1, final_solution)
        s[left], s[i] = s[i], s[left]
        i += 1

s = input()
final_solution = []
permute(list(s), 0, final_solution)
for s in sorted(set(final_solution)):
    print(s)
