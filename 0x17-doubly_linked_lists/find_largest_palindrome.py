largest_palindrome = 0

# Iterate through all possible 3-digit numbers
for num1 in range(100, 1000):
    for num2 in range(100, 1000):
        product = num1 * num2
        if str(product) == str(product)[::-1] and product > largest_palindrome:
            largest_palindrome = product

# Save the result to the file 102-result
with open("102-result", "w") as result_file:
    result_file.write(str(largest_palindrome))

