def gcd(a, b):
    if b == 0:
        return a
    if b > a:
        return gcd(b, a)
    # This means b <= a
    return gcd(b, a % b)

print gcd(24, 18)
# Output: 6
print gcd(54, 36)
# Output: 18
print gcd(120, 428860)
# Output: 20
print gcd(324, 8460592)
# Output: 4
