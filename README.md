<h1 align="center">Projeto de Manipulador Robótico com 4 eixo de liberdade</h1>

<h2 align="left">Introdução</h2>
<p align="justify">Este manipulador robótico foi feito de maneira que fosse possível simular uma garra robótica industrial porém utilizando comando de programação C++.</p>
<p align= "justify">Utilizando uma interface para visualizar as informações (como o tempo), podemos gravar movimentos para que o manipulador realize automaticamente caso seja necessário, além de podermos reescrever eles, sem ser uma quantidade de movimentos definida, será limitada pela memória do microcontrolador.</p>
<h2 align="left">Lista de Materiais</h2>
<p align= "left">-Suporte mecânico</p>
<p align= "left">-01 Arduino Uno R3</p>
<p align= "left">-04 Servo motores de 9g</p>
<p align= "left">-02 módulos Joysticks com botão</p>

<h2 align= "left">Modo de funcionamento</h2>
<p align = "justify">O modo básico de funcionamento acontece da seguinte maneira: ao movimentar os joysticks o manipulador irá se movimentar em 4 eixos possíveis, cada um configurado com um eixo do módulo, por exemplo, eixo X do joystick 1 irá movimentar o servo motor 1. Foi utilizado um comando delay na escrita do programa (ele para o microcontrolador por 5ms) pois os servo motores se movimentam em uma velocidade elevada, para evitar trancos e possíveis danos a estrutura foi adicionado esta linha, porém é possível incrementar o programa alterar esta velocidade utilizando a biblioteca VarSpeedServo.</p>
<p align = "justify">O botão presente no joystick (conectado ao pino 4 do arduino) tem algumas funções dependendo do tempo que for mantido pressionado:<br>
  -Tempo maior que 2s e menor que 5s: A sequência de movimentos que foi gravada será executada uma vez;<br>
  -Tempo maior que 5s e menor que 10s: Entra em modo de programação de movimentos;<br>
  -Tempo maior que 10s: Apaga os movimentos gravados anteriormente.
 </p>
<h2 align = "left">Modo de programação</h2>
<p align="justify">Ao ativar o modo de programação com um pressionamento do botão por mais de 5s, mas menos de 10s, uma mensagem será exibida no Serial Monitor. Em seguida, é necessário definir a quantidade de movimentos necessários para realizar a tarefa. Cada pulso no botão, com duração superior a 100ms e inferior a 1000ms, será registrado como um movimento a ser gravado. <br>Após atingir o número desejado de movimentos, pressione o botão por mais de 1s para iniciar a gravação (o total de movimentos será indicado no Monitor Serial). Nesse momento, o controle do robô estará novamente operante. Execute um movimento e, em seguida, pressione o joystick para salvar essa posição.<br> Repita esse processo até alcançar a quantidade predefinida de movimentos, encerrando assim o modo de programação e retornando à operação básica do manipulador.</p>

<a href="https://youtu.be/sLVkXOzmOBQ" target="_blank" rel="noopener noreferrer">
  <img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcSGqKrNaV0gzOSkg0XL_8foZGV8-WsLLqe86w&usqp=CAU" alt="Vídeo de demonstração">
</a>




