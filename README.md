# Philosophers
Philosphy always was something that I loved. I would consider myself a determistic monistic utilitaristic hedonist. (for people acutally reading discriptions: The Ego Tunnel by Metzinger is an awesome book recommendation ;) <br>
But after the philo project I had enough Philosophy for the rest of the year! 
<img src="https://github.com/42elenz/42_philosophers/blob/master/resources/eval.png"/><br>

## Introduction

This is taken from the subject.pdf.<br>
<p float="left">
<img src="https://github.com/42elenz/42_philosophers/blob/master/resources/introduction.png" height="300"/>
<img src="https://github.com/42elenz/42_philosophers/blob/master/resources/philosophers_example.png" height="300"/>
<p>

To run the simulation a few variables are needed:

1. number_of_philosophers: is the number of philosophers and also the number of forks.
2. time_to_die: is in milliseconds, if a philosopher doesn’t start eating ’time_to_die’milliseconds after starting their last meal or the beginning of the simulation,it dies.
3. time_to_eat: is in milliseconds and is the time it takes for a philosopher to eat. During that time they will need to keep the two forks.
4. time_to_sleep: is in milliseconds and is the time the philosopher will spend sleeping.
5. number_of_times_each_philosopher_must_eat: argument is optional, if all philosophers eat at least ’number_of_times_each_philosopher_must_eat’ the simulation will stop. If not specified, the simulation will stop only at the death of a philosopher.
<br>
Each action of a philosopher will result in his state beeing printed in the correct order and with a timestamp and his number.<br>
A philosopher can:

- grab a fork
- eat
- sleep
- think
- die

## Usage
To compile the programm run `make all` in the root of the project.<br>
Then run `./philo` with the parameters you want to test explained in [Introduction](https://github.com/42elenz/42_philosophers#Introduction) as 1. 2. 3. 4. and 5.<br><br>
i.e.: `./philo 4 20000 100 250 9`<br>

![gif](https://github.com/42elenz/42_philosophers/blob/master/resources/philo.gif)
