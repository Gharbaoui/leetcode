import matplotlib.pyplot as plt

categories = ['Category A', 'Category B', 'Category C', 'Category D']

values = list(reversed([24, 16, 30, 2, 18, 24, 20, 2, 6, 4]))

def addlabels(x,y):
    for i in range(len(x)):
        plt.text(i,y[i],y[i])

x_values = list(range(0, len(values)))
plt.bar(x_values, values, width=0.3)
addlabels(x_values, values)
plt.xlabel('i')
plt.xticks(x_values)
plt.ylabel('height')
plt.title('container most water')
# plt.gca().set_facecolor('black')  # Set the background color to black
plt.show()