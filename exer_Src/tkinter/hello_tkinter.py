###library import.###
import tkinter

###define variables###
root=tkinter.Tk()   #create tkinter instance

label=tkinter.Label(root, text='Hello Tkinter')

###main code###
label.pack()        # collocate label
root.mainloop()     # denote root
