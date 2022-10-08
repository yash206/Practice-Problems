# Given an unsorted integer array nums, return the smallest missing positive integer.
# You must implement an algorithm that runs in O(n) time and uses constant extra space.
# Input: nums = [1,2,0]
# Output: 3
# Input: nums = [3,4,-1,1]
# Output: 2
# Input: nums = [7,8,9,11,12]
# Output: 1

def firstMissingPositive(nums: list) -> int:
    maximum=1
    numset=set(nums)
    while maximum in numset:
        maximum+=1
    return maximum

if __name__ == '__main__':
    a = firstMissingPositive([1,2,0])
    print(a)
    b = firstMissingPositive([3,4,-1,1])
    print(b)
    c = firstMissingPositive([7,8,9,11,12])
    print(c)

