### library import ###
from tkinter import *

### main code ###
root = Tk()

lbl = Label(root, text = 'Name')
lbl.grid(row = 0, column = 0)

txt = Entry(root)
txt.grid(row = 0, column = 1)

btn = Button(root, text = 'OK', width = 15)
btn.grid(row = 1, column = 1)

root.mainloop()
