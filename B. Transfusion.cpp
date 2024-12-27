def can_equalize(test_cases):
    results = []
    for case in test_cases:
        n = case[0]
        a = case[1]
        
        total_sum = sum(a)
        
        # Check if total_sum is divisible by n
        if total_sum % n != 0:
            results.append("NO")
            continue
        
        target_value = total_sum // n
        
        # Check if we can achieve non-negative values
        current_balance = 0
        possible = True
        
        for value in a:
            current_balance += value - target_value
            if current_balance < 0:
                possible = False
                break
        
        results.append("YES" if possible else "NO")
    
    return results

# Example usage:
t = 8
test_cases = [
    (3, [3, 2, 1]),
    (3, [1, 1, 3]),
    (4, [1, 2, 5, 4]),
    (4, [1, 6, 6, 1]),
    (5, [6, 2, 1, 4, 2]),
    (4, [1, 4, 2, 1]),
    (5, [3, 1, 2, 1, 3]),
    (3, [2, 4, 2])
]

results = can_equalize(test_cases)
for result in results:
    print(result)
