#Tip Calculator

print("Welcome to Tip Calculator!")
billWithoutTip=float(input("What was the total bill? $"))
tip=int(input("How much tip you want to give? $"))
people=int(input("Number of people to Split bill with: "))
tipPer=tip/100
totalTip=billWithoutTip*tipPer
totalbill=billWithoutTip+totalTip
final=totalbill/people
print("Each person will pay: $"+"{:.2f}".format(final))