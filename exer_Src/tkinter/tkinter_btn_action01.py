
#
# processing when button pressed
#
#


### import library ###
import tkinter as tk

### create tk instance ###
root = tk.Tk()

def func():
    #print message to shell
    print('Pushed')
    #func() exit


### create button ###
button = tk.Button(root, text = 'push!', command = func)

### locate button ###
button.pack()

### denote root ###
root.mainloop()
