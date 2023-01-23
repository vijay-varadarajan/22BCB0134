nums = list(eval(input("Enter a list of numbers: ")))
n = int(input("Enter N: "))
nums = sorted(nums, reverse=True)
print(nums[n-1])
