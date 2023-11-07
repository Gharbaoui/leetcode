import matplotlib.pyplot as plt

categories = ['Category A', 'Category B', 'Category C', 'Category D']

values = [8, 2, 3, 5, 4, 2, 3, 7]

def addlabels(x,y):
    for i in range(len(x)):
        plt.text(i,y[i],y[i])

ax = plt.axes()
ax.set_facecolor('lightblue')
barColor = (0, 0, 0, 1)
x_values = list(range(0, len(values)))
plt.ylim(1, 10)
plt.bar(x_values, values, width=1, color=barColor)
addlabels(x_values, values)
plt.xlabel('i')
plt.xticks(x_values)
plt.ylabel('height')
plt.title('trapping rain water')
# plt.gca().set_facecolor('black')  # Set the background color to black
plt.show()