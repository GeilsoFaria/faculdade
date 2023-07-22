from tkinter import *

menu= Tk()
menu.title("Alterar propriedades")
menu.geometry("500x500+10+10")
menu['bg']='white'

#botao
btn= Button(menu,text="Clique",background="green") #button(objPai, propriedades)
btn.pack()
#botao + eventos
def botao_clique(num):
    soma=num
    print('num1 + num2 = ',soma)
    
botao= Button(menu,text="Executar", command=lambda:botao_clique(5)) #lambda passa algum valor para funcao
botao.pack()


menu.mainloop()