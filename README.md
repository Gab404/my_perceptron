<div id="top"></div>

[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![LinkedIn][linkedin-shield]][linkedin-url]



<!-- PROJECT LOGO -->
<br />
<div align="center">
  <h3 align="center">Perceptron Algorithm</h3>

  <p align="center">
    Implementation of perceptron algorithm with C language.
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

[![Product Name Screen Shot][schema-network]]

The perceptron is a simplest neural network with only one neuron that can classify two types of linearly separable data.

The neuron has several weights, as many as type of input data, a bias, a linear function and a linearization function (sigmoid).

[![Product Name Screen Shot][loss-function]]

I use the Log Loss function to calculate the loss of the network and I use the gradient descent to propagate gradients. 


<p align="right">(<a href="#top">back to top</a>)</p>



### Built With


* [C Language](https://fr.wikipedia.org/wiki/C_(langage))

<p align="right">(<a href="#top">back to top</a>)</p>


<!-- USAGE EXAMPLES -->
## Usage

Use the `Makefile` to get started on Linux.

Use the `CMakeLists.txt` or `gcc ./src/*.c` to get started on Windows



The data input file should be as follows:

      numberData numberInput
      firstInput ... nInput label
      firstInput ... nInput label
      ...

Example:

      150 2
      5.4 1.7 blue
      6.9 5.0 red
      ...



Weights are saved as follows in `./save/`:

      numberData numberInput
      learningRate
      weight1
      ...
      weightN
      bias

<p align="right">(<a href="#top">back to top</a>)</p>


<!-- CONTACT -->
## Contact

Gabriel GUIET-DUPRE - [in: gabriel-guiet-dupre](https://linkedin.com/in/gabriel-guiet-dupre) - gabriel.guietdupre@edu.ece.fr

Project Link: [https://github.com/gab_gdp/my_perceptron](https://github.com/Gab404/my_perceptron)

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/Gab404/Best-README-Template.svg?style=for-the-badge
[contributors-url]: https://github.com/Gab404/runner/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/Gab404/Best-README-Template.svg?style=for-the-badge
[forks-url]: https://github.com/Gab404/runner/network/members
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/gabriel-guiet-dupre
[schema-network]: ./assets/schema.png
[loss-function]: ./assets/logLoss.png
