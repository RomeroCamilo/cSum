import cgetSum

def file_to_list(file_name): # function that read from a .txt file and store values into list #

    numbers = []

    f = open(file_name,"r")

    if f.closed:
        print("File did not open.")
    else:
        print("File successfully opened.")
        numbers = []
        for line in f:
            line = line.split()
            for number in line:
                number = float(number)
                numbers.append(number)
    
    f.close()
    
    return numbers

numbers2 = file_to_list("numbers.txt")

result = cgetSum.cSum((1,2,3,4,5))

print(result)

result = cgetSum.cSum((1.2, 2.2, 3.3, 100))

print(result)

result = cgetSum.cSum([1, 2, 3, 33.1 , 101])

print(result)

result = cgetSum.cSum([1,2,3,4,5,55.5,2])

print(result)

result = cgetSum.cSum([1,2.2])

print(result)

result = cgetSum.cSum(1,2,3,4.4)

print(result)

result = cgetSum.cSum(1,1.1,2,3,5)

print(result)

result = cgetSum.cSum()

print(result)

result = cgetSum.cSum(())

print(result)

result = cgetSum.cSum([])

print(result)