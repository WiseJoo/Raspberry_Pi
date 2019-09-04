
#
# print execute result using Label widget
#
#


### import library ###
import tkinter as tk

### create tk instance ###
root = tk.Tk()

### push processing routine ###
def func():
    #change the label indication
    label.config(text = 'Pushed')
    #func() exit


### create label ###
label = tk.Label(root, text = 'Push Button')

### locate label ###
label.pack()

### create button ###
button = tk.Button(root, text = 'Push!', command = func)

### locate button ###
button.pack()

### denote root ###
root.mainloop()
