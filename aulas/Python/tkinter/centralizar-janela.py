from tkinter import *

menu_incial= Tk()
menu_incial.title("Centralizar formulario")
#dimensoes da janela
largura=500
altura=300

#resolução do sistema
largura_screen= menu_incial.winfo_screenwidth()#captura largura da tela 
altura_screen=menu_incial.winfo_screenheight()#captura altura da tela
print(largura_screen,altura_screen)
#posicao da janela
pos_x=largura_screen/2-largura/2
pos_y=altura_screen/2-altura/2

menu_incial.geometry("%dx%d+%d+%d"%(largura,altura,pos_x,pos_y))
menu_incial.mainloop()