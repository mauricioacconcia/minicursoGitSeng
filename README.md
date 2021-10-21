<div id="top"></div>
<!--
***este é um modelo modificado
***original em: https://github.com/othneildrew/Best-README-Template
-->



<!-- PROJECT SHIELDS -->
&emsp;
&emsp;
[![Contributors][contributors-shield]][contributors-url]
[![Commits][commits-shield]][commits-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![LinkedIn][linkedin-shield]][linkedin-url]
<!-- [![MIT License][license-shield]][license-url] -->



<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="http://eventos.uniararas.br/home/430" target="_blank">
    <img src="Images/logo.jpg" alt="Logo" width="400" height="110">
  </a>
</div>

<p> 
    <div align="center">
        <h1><a href="https://github.com/mauricioacconcia/minicursoGitSeng" target="_blank">Minicurso de GitHub</a></h1>
    </div>
</p>


<!-- TABLE OF CONTENTS -->
<details>
  <summary>Sumário</summary>
  <ol>
    <li><a href="#instalação">Instalação</a></li>
    <li><a href="#projetos">Criação de Projetos</a></li>
    <li><a href="#Configuração">Configuração do Ambiente</a></li>
    <li><a href="#commit">Primeiro Commit</a></li>
    <li><a href="#Branches">Fazendo um Branch</a></li>
  </ol>
</details>


<!-- ABOUT THE PROJECT -->
## Instalação

A instalação do github depende do seu sistema operacional. 

Acessar o link de <a href="https://git-scm.com/downloads" target="_blank">Instalação</a>, escolher seu sistema operacional e fazer o download dos arquivos.

Após fazer o download é só executar o arquivo.

<p align="right">(<a href="#top">back to top</a>)</p>


## Projetos

O GIT é um gerenciador de versões. Sendo assim a organização básica é um conjunto de diretórios que contém o projeto. 

A ideia de utilização é basicamente modificar arquivos do projeto e manter o sincronismo entre uma pasta local e o repositório que está online. A vantagem de se ter um repositório online é que a colaboração é possível apenas com compartilhamento de links e permissões de utilização.

Existe uma diferença entre o GIT e o GITHub. Em 2005, Linus Torvalds desenvolveu o GIT, que desde então tem sido ativamente mantido por Junio ​​Hamano, um engenheiro de software japonês. É um dos mais famosos sistemas de controle de versão de código aberto e milhões de projetos no mundo inteiro o utilizam para seu controle de versão (incluindo projetos comerciais e de código aberto).

O GITHub é um sistema web que cria uma interface para utilização do GIT. Recentemente adquirido pela Microsoft, o sistema permite a criação de projetos públicos e privados, porém para poder obter todo o poder da ferramenta para projetos privados é necessário adquirir uma licensa.

Ao criar uma conta no GITHub é possível acessar essa conta por SSH e controlar remotamente o seu projeto. Para isso é necessário configurar o ambiente antes de utilizar a ferramenta.

<p align="right">(<a href="#top">back to top</a>)</p>


## Configuração

Vamos então ao passo-a-passo para configurar seu ambiente de trabalho com o GIT. Dois passos iniciais são necessários:

1 - Instale o Git pelo link apresentado anteriormente
2 - Crie uma conta no GITHub

A partir deste momento é necessário configurar seu GIT local (instalado na sua máquina) para trabalhar com sua conta no GITHub. Isso pode ser feito pela configuração do acesso SSH.

3 - Configurar o email da sua conta do GITHub no seu GIT local
  ```sh
  git config --global user.email "seu@email.com"
  ```
4 - Configurar o usuário do seu GIT local como o usuário do GITHub
```sh
  git config --global user.name "seuusuario"
  ```
A autenticação de usuário por SSH ocorre com chaves públicas e privadas. Para isso é necessário gerar a chave no seu computador e configurar a chave na sua conta do GITHub. Para listar as chaves existentes utiliza-se o comando:
```sh
  ls -al ~/.ssh
  ```
Sempre que você instalar o GIT em um computador ou mudar o ambiente de trabalho é recomendado que se crie uma chave nova para a segurança do processo de desenvolvimento.

5 - Geração da chave pública e privada para configuração no GITHub

-- Para criar uma chave ed25519, executar: 
```sh
  ssh-keygen -t ed25519 -C "seu@email.com"
  ```
-- Para criar uma chave rsa, executar: 
```sh
  ssh-keygen -t rsa -b 4096 -C "seu@email.com"
  ```
Neste caso iremos utilizar a chave ed25519. Duas questões importantes ao criar a chave são: a hora que for solicitado o nome do arquivo para salvar a chave você deve apertar "enter" sem indicar um nome para que seja criado o arquivo padrão, e SEMPRE coloque uma senha.

Feito este procedimento é necessãrio adicionar a chave ao seu GIT local. Para isso executar:

-- Rodar o ssh-agent: 
```sh
  eval $(ssh-agent -s)
  ```
-- Incluir a chave privada: 
```sh
  ssh-add ~/.ssh/id_ed25519
  ```
Após adicionar a chave ao SSH local seu GIT estará configurado, porém ainda é necessário configurar a conta do GIHub. Para isso é necessário inserir a chave em sua conta. O primeiro passo é copiar a chave para a área de transferência.

-- No Windows: 
```sh
  clip < ~/.ssh/id_ed25519.pub
  ```
-- No Linux: 
```sh
  cat ~/.ssh/id_ed25519.pub
  ```
Então, para adicionar a chave na sua conta do GITHub siga os passos:

<ol>
  <li>Abra o Github e vá no ícone de perfil > Settings, no canto superior direito.</li>
  <li>Na barra lateral de configurações do usuário, clique em "SSH and GPG keys".</li>
  <li>Clique no botão "New SSH key"</li>
  <li>No campo "Título", adicione um rótulo descritivo para a nova chave. Por exemplo, se estiver usando seu computador pessoal, você pode chamar essa chave de "Computador pessoal".</li>
  <li>Cole a chave pública que está na área de transferência no campo "Chave".</li>
  <li>Clique em "Add SSH key"</li>
</ol>

6 - Teste de comunicação

O teste da comunicação pode ser feito com o seguinte comando:
```sh
  ssh -T git@github.com
  ```
Caso solicitada a confirmação digite "Yes". Deve aparecer uma mensagem um pouco longa confirmando sua autenticação, e também indicando que o GIThub não prove acesso pelo shell. Erros de autenticação de chave podem ser resolvidos com auxílio da documentação oficial presente neste <a href="https://docs.github.com/en/authentication/troubleshooting-ssh/error-permission-denied-publickey" target="_blank">link</a>.

Ao final destes procedimentos o seu sistema local estará apto a gerenciar repositórios remotos em sua conta do GITHub sem maiores problemas.

<p align="right">(<a href="#top">back to top</a>)</p>

## Commit

O processo de trabalho no GIT entre a máquina local e a conta do GitHub pode ser inciiado de duas formas:

A - Criando uma pasta no seu computador na qual serão colocados os arquivos do projeto

Ao criar uma pasta para seu projeto é necessário navegar até a pasta criada. O BASH que estamos utilizando possui os mesmos comandos do terminal do linux. Um resumo deles pode ser visto <a href="https://www.devmedia.com.br/comandos-importantes-linux/23893" target="_blank">aqui</a>.

Após estar na pasta atual do projeto é necessário iniciar sua parte como um diretório GIT. Isso é feito com o comando 
```sh
  git init
  ```
Quando executado em uma pasta este comando irá criar uma pasta .git oculta em seu diretório permitindo seu gerenciamento. O segundo passo é "linkar" esta pasta com o seu projeto no GITHub. A melhor forma de fazer isso é criando um projeto no site inicial e depois fazer o link. Então no GITHub crie seu repositório:

<ol>
  <li>Clique no símbolo de + no topo da tela</li>
  <li>Depois em New Repository</li>
  <li>Preencha um nome e uma descrição para o projeto</li>
  <li>Clique em Create repository.</li>
</ol>

Para "linkar" seu projeto com o seu repositório no github você vai usar o comando 
```sh
  git remote add origin https://github.com/user/seuprojeto.git
  ```

Para adicionar os arquivos no índice do git executar o seguinte comando:
```sh
  git add .
  ```

Feito isso você configura o seu origin para seu projeto criado na conta do GITHub. A partir disso é possível executar os comandos:
```sh
  git commit -m "descrição rápida do commit"
  git push origin master
  ```
O primeiro comando irá "formalizar" o conjunto de morificações adicionados ao índice do GIT do seu projeto como uma nova atualização, associando a descrição apresentada aos arquivos modificados.

O segundo comando irá efetivamente enviar os arquivos ao seu repositório no GITHub. Nesta etapa é importante apresentar o conceito de Master e Branches. Caso apareça uma tela de login selecionar -> Login com o browser e autorizar o aplicativo no botão verde.

Quando trabalhamos com controle de versões, a versão corrente de um projeto seria a versão Master. Nela estão os arquivos mais estáveis que irão garantir que o projeto funciona, além disso normalmente os arquivos do master são disponibilizados para os usuários apenas após verificações e testes por parte do responsável pelo projeto.

No caso de projetos mais simples trabalhamos diretamente com a Master já que não há perigo de modificações fora de controle por parte do programados (ou assim esperamos). Porém, no caso de projetos em colaboração cria-se normalmente uma Branch e modifica-se o código desta Branch. Ao finalizar as modificações o "dono" do projeto deve ser notificado para que realize os testes e substitua a Master atual pela sua Branch modificada. Este procedimento é abordado mais à frente.

B - Clonando um diretório existente no GITHub em seu HD para modificação

Para clonar um repositório do GITHub utiliza-se o comando
```sh
  git clone https://github.com/endereçodoprojeto
  ```

Este comando já irá criar uma pasta nova no diretório atual com o mesmo nome do projeto, fazer o download de todos os arquivos e deixar na versão mais recente para trabalhar. Para que seja possível trabalhar em seus repositórios sem problemas a autenticação por senha não é mais funcional, sendo necessária a geração de um token.

Para criar um token:
<ol>
  <li>Profle->Settings</li>
  <li>Developer Settings/li>
  <li>Personal Access Tokens</li>
  <li>Generate New Token (botão)</li>
  <li>Na parte "Note" explique qual o motivo da criação para não se perder</li>
  <li>Configure as permissões</li>
  <li>Generate Token (botão)</li>
  <li>Copie o valor do token gerado</li>
</ol>

Após ter feito as modificações na pasta, adicionado os arquivos com o git add, feito o seu commit é necessário fazer o push. Os comandos são os mesmos acima.

```sh
  git add .
  git commit -m "descrição rápida do commit"
  git push origin master
  ```
No caso, quando você for fazer o push pode ser solicitado o login. Se for este o caso, feche todas as janelas gráficas que aparecerem a nas linhas de comando digite seu usuário e no lugar da senha digite o token gerado.

Desta maneira a autenticação não irá falhar e você poderá modificar o projeto. Isso ocorreu no meu caso porque eu gerei a pasta de outro computador com outra chave e por algum motivo as minhas novas modificações em uma chave nova não foram previamente autorizadas para a pasta em questão, mesmo sendo eu mesmo o usuário.

Se você chegou até aqui já consegue criar e gerenciar seus próprios projetos sem maiores problemas. Porém, o interessante na utilização do GIThub para projetos é a colaboração. Sendo assim vamos aprender como colaborar corretamente com um determinado projeto!

<p align="right">(<a href="#top">back to top</a>)</p>

## Branches

Um branch é uma modificação do projeto. O branch é feito para que seja possível modificar os arquivos do projeto sem que os funcionais sejam alterados.

Para criar um branch é necessário executar:
```sh
  git branch nome_do_branch
  ```

Para que as alterações sejam feitas no branch correto é preciso mudar o contexto no qual se está inserido. Isto é feito com o comando:
```sh
  git checkout nome_do_contexto.
  ```

O contexto pode ser o master ou algum dos branches criados. Também é possível visualizar toda a árvore de modificações com o comando:
```sh
  git log --pretty=format:"%h %s" --graph
  ```

Apos as modificações é necessário fazer uma junção (MERGE) entre o que foi modificado e o arquivo principal. Nessa junção as modificações substituem os arquivos anteriores da branch escolhida. Para fazer a junção, entre o contexto atual e outro contexto, utilza-se o comando:
```sh
  git merge contexto_que_deseja_juntar
  ```
Importante, esteja no contexto que não foi modificado e execute o merge com o contexto já modificado. Então, para finalizar, como contribuir para um determinado projeto?

1. Clone o projeto em sua máquina
2. Crie uma nova Branch
3. Mofique os arquivos e realize os commits
4. Envie os arquivos para a branch
5. Abra um request para que o responsável pelo diretório faça o merge com o master se necessário.

<p align="right">(<a href="#top">back to top</a>)</p>

## Fontes
<ol>
<li>https://dicasdeprogramacao.com.br/como-instalar-o-git-no-windows/</li>
<li>https://dev.to/dxwebster/como-conectar-ao-github-com-chaves-ssh-1i41</li>
<li>https://shields.io/</li>
<li>https://gist.github.com/leocomelli/2545add34e4fec21ec16</li>
<li>https://rogerdudler.github.io/git-guide/index.pt_BR.html</li>
<li>https://githowto.com/pt-BR</li>
<li>https://opensource.org/licenses</li>
</ol>

<!-- MARKDOWN LINKS & IMAGES -->
[contributors-shield]:https://img.shields.io/github/contributors/mauricioacconcia/minicursoGitSeng?style=for-the-badge
<!-- alterar seus contributors-->
[contributors-url]: https://github.com/mauricioacconcia/minicursoGitSeng/graphs/contributors
[commits-shield]: https://img.shields.io/github/commit-activity/w/mauricioacconcia/minicursoGitSeng?style=for-the-badge
<!-- alterar seus commits-->
[commits-url]: https://github.com/mauricioacconcia/minicursoGitSeng/commits/master
[stars-shield]: https://img.shields.io/github/stars/mauricioacconcia/minicursoGitSeng?style=for-the-badge
<!-- alterar seus stats -->
[stars-url]: https://github.com/mauricioacconcia/minicursoGitSeng/stargazers
[issues-shield]: https://img.shields.io/github/issues/mauricioacconcia/minicursoGitSeng?style=for-the-badge
<!-- alterar suas issues -->
[issues-url]: https://github.com/mauricioacconcia/minicursoGitSeng/issues
<!-- alterar sua licença -->
<!--[license-shield]: https://img.shields.io/github/license/othneildrew/Best-README-Template.svg?style=for-the-badge
[license-url]: https://github.com/othneildrew/Best-README-Template/blob/master/LICENSE.txt-->
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
<!-- alterar seu linkedin -->
[linkedin-url]: https://www.linkedin.com/in/acconcia/
<!-- alterar seu logo -->
[product-screenshot]: images/screenshot.png
