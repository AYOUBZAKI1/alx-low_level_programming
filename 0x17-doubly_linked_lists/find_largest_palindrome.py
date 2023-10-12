# Function to check if a number is a palindrome
def is_palindrome(num):
    return str(num) == str(num)[::-1]

largest_palindrome = 0

# Iterate through all possible products of two 3-digit numbers
for num1 in range(100, 1000):
    for num2 in range(100, 1000):
        product = num1 * num2
        if is_palindrome(product) and product > largest_palindrome:
            largest_palindrome = product

# Save the result to the file 102-result
with open("102-result", "w") as result_file:
    result_file.write(str(largest_palindrome))

