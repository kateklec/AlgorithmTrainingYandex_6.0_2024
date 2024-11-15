# AlgorithmTrainingYandex_6.0_2024
## Контест 1
### A. Плот
[1_A_Plot.cpp](https://github.com/kateklec/AlgorithmTrainingYandex_6.0_2024/blob/main/AlgorithmTraining_6.0/1_A_Plot.cpp)
<details>
  <summary>Условие задачи</summary>
  
  **Описание:**  
  Посередине озера плавает плот, имеющий форму прямоугольника. Стороны плота направлены вдоль параллелей и меридианов. Введём систему координат, в которой ось OX направлена на восток, а ось ОY – на север. Пусть юго-западный угол плота имеет координаты (x1, y1), северо-восточный угол – координаты (x2, y2). 
  Пловец находится в точке с координатами (x, y). Определите, к какой стороне плота (северной, южной, западной или восточной) или к какому углу плота (северо-западному, северо-восточному, юго-западному, юго-восточному) пловцу нужно плыть, чтобы как можно скорее добраться до плота.
  
  **Формат ввода:**  
  Программа получает на вход шесть чисел в следующем порядке: `x1`, `y1` (координаты юго-западного угла плота), `x2`, `y2` (координаты северо-восточного угла плота), `x`, `y` (координаты пловца). Все числа целые и по модулю не превосходят 100. Гарантируется, что `x1 < x2`, `y1 < y2`, `x ≠ x1`, `x ≠ x2`, `y ≠ y1`, `y ≠ y2`, и координаты пловца находятся вне плота.
  
  **Формат вывода:**  
  Если пловцу следует плыть к северной стороне плота, программа должна вывести символ "N", к южной — символ "S", к западной — символ "W", к восточной — символ "E". Если пловцу следует плыть к углу плота, нужно вывести одну из следующих строк: "NW", "NE", "SW", "SE".
  
</details>

### B. Майки и носки

[1_B_T-shirtsAndSocks.cpp](https://github.com/kateklec/AlgorithmTrainingYandex_6.0_2024/blob/main/AlgorithmTraining_6.0/1_B_T-shirtsAndSocks.cpp)

<details>
  <summary>Условие задачи</summary>
  
  **Описание:**  
  Как известно, осенью и зимой светает поздно, и так хочется утром ещё хоть немного поспать, а не идти в школу! Некоторые школьники готовы даже одеваться, не открывая глаз, лишь бы отложить момент пробуждения. Вот и Саша решил, что майку и носки он вполне может вытащить из шкафа на ощупь с закрытыми глазами и только потом включить свет и одеться. В шкафу у Саши есть два ящика. В одном из них лежит `A` синих и `B` красных маек, в другом — `C` синих и `D` красных пар носков. Саша хочет, чтобы и майка, и носки были одного цвета. Он вслепую вытаскивает `M` маек и `N` пар носков. В первое же утро Саша задумался, какое минимальное суммарное количество предметов одежды (`M + N`) он должен вытащить, чтобы среди них гарантированно оказались майка и носки одного цвета. Какого именно цвета окажутся предметы одежды, для Саши совершенно неважно. 

  **Формат ввода:**  
  На вход программе подаются четыре целых неотрицательных числа `A`, `B`, `C`, `D`, записанных в отдельных строках: `A` — количество синих маек, `B` — количество красных маек, `C` — количество синих носков, `D` — количество красных носков. Все числа не превосходят 10^9. Гарантируется, что в шкафу есть одноцветный комплект из майки и носков.
  
  **Формат вывода:**  
  Программа должна вывести два числа: количество маек `M` и количество пар носков `N`, которые должен взять Саша. Необходимо, чтобы среди `M` маек и `N` пар носков обязательно нашлась одноцветная пара, при этом сумма `M + N` должна быть минимальной.
  
  **Примечания:**  
  В примере из условия в шкафу лежит `A = 6` синих маек и `B = 2` красных маек. Если взять 3 майки, то среди них обязательно найдётся синяя. В другом ящике лежит `C = 7` пар синих носков и `D = 3` пары красных носков. Если взять 4 пары, то среди них обязательно будет пара синих носков. Поэтому если взять вслепую 3 майки и 4 пары носков, то среди них обязательно найдётся одноцветный (синий) комплект из майки и носков.

</details>

### C. Надпись на табло

[1_C_DisplayBoardMessage.cpp](https://github.com/kateklec/AlgorithmTrainingYandex_6.0_2024/blob/main/AlgorithmTraining_6.0/1_C_DisplayBoardMessage.cpp)

<details>
  <summary>Условие задачи</summary>
  
  **Описание:**  
  Вы получили доступ к одной из камер наблюдения в особо секретной организации. В зоне видимости камеры находится табло, с которого вы постоянно считываете информацию. Теперь вам нужно написать программу, которая по состоянию табло определяет, какая буква изображена на нём в данный момент. Табло представляет из себя квадратную таблицу, разбитую на `n×n` равных квадратных светодиодов. Каждый диод либо включён, либо выключен. Введём систему координат, направив ось OX вправо, а ось OY — вверх, приняв сторону диода равной 1. 

  На табло могут быть изображены только следующие буквы:
  
  • `I` — прямоугольник из горящих диодов.  
  • `O` — прямоугольник из горящих диодов с углами `(x1,y1)` и `(x2,y2)`, внутри которого есть прямоугольник из выключенных диодов с координатами углов `(x3,y3)` и `(x4,y4)`. При этом границы выключенного прямоугольника не должны касаться внешнего, то есть `x1 < x3 < x4 < x2` и `y1 < y3 < y4 < y2`.  
  • `C` — прямоугольник из горящих диодов с углами `(x1,y1)` и `(x2,y2)`, внутри которого есть прямоугольник из выключенных диодов с координатами углов `(x3,y3)` и `(x4,y4)`. При этом правая граница выключенного прямоугольника находится на правой границе внешнего прямоугольника, то есть `x1 < x3 < x4 = x2` и `y1 < y3 < y4 <y2`.  
  • `L` — прямоугольник из горящих диодов с углами `(x1,y1)` и `(x2,y2)`, внутри которого есть прямоугольник из выключенных диодов с координатами углов `(x3,y3)` и `(x4,y4)`. При этом правые верхние углы выключенного прямоугольника и внешнего прямоугольника совпадают, то есть `x1 < x3 < x4 = x2` и `y1 < y3 < y4 = y2`.  
  • `H` — прямоугольник из горящих диодов с углами `(x1,y1)` и `(x2,y2)`, внутри которого находятся 2 прямоугольника из выключенных диодов с координатами углов `(x3,y3)`, `(x4,y4)` у первого и `(x5,y5)`, `(x6,y6)` у второго. Выключенные прямоугольники должны иметь одинаковую ширину, находиться строго один под другим, один касаясь верхней стороны, а другой касаясь нижней стороны внешнего прямоугольника, то есть `x1 < x3 = x5 < x4 = x6 < x2` и `y1 = y3 < y4 < y5 < y6 = y2`.  
  • `P` — прямоугольник из горящих диодов с углами `(x1,y1)` и `(x2,y2)`, внутри которого находятся 2 прямоугольника из выключенных диодов с углами `(x3,y3)`, `(x4,y4)` у первого и `(x5,y5)`, `(x6,y6)` у второго. Правый нижний угол первого выключенного прямоугольника должен совпадать с правым нижним углом внешнего прямоугольника, а другой выключенный прямоугольник должен находиться выше и не касаться других границ, также левые границы двух выключенных прямоугольников должны совпадать, то есть `x1 < x3 = x5 < x4 = x6 = x2` и `y1 = y3 < y4 < y5 < y6 = y2`.
  
  • Любое другое состояние табло считается буквой **X**.

  **Формат ввода:**  
  В первой строке входных данных находится одно число `n` (1 ≤ n ≤ 10) — сторона табло. В следующих `n` строках находятся строки длины `n` из символов `.` и `#` — строки таблицы. `.` обозначает выключенный квадратный диод табло, а `#` — горящий.

  **Формат вывода:**  
  Программа должна вывести единственный символ: если данная таблица подходит под одно из описаний букв `I`, `O`, `C`, `L`, `H`, `P`, то выведите её (все буквы — английские). Если же данная таблица не подходит ни под какие условия, то выведите `X`.

</details>

### D. Кондиционер (составление тестов)

[1_D_AirConditioner(Tests).cpp](https://github.com/kateklec/AlgorithmTrainingYandex_6.0_2024/blob/main/AlgorithmTraining_6.0/1_D_AirConditioner(Tests).cpp)

<details>
  <summary>Условие задачи</summary>
  
  **Описание:**  
  На соревновании участникам была предложена следующая задача:  
  ——  
  В офисе, где работает программист Петр, установили кондиционер нового типа. Этот кондиционер отличается особой простотой в управлении. У кондиционера есть всего лишь два управляемых параметра: желаемая температура и режим работы.

  Кондиционер может работать в следующих четырех режимах:
  
  - `freeze` — охлаждение. В этом режиме кондиционер может только уменьшать температуру. Если температура в комнате и так не больше желаемой, то он выключается.
  - `heat` — нагрев. В этом режиме кондиционер может только увеличивать температуру. Если температура в комнате и так не меньше желаемой, то он выключается.
  - `auto` — автоматический режим. В этом режиме кондиционер может как увеличивать, так и уменьшать температуру в комнате до желаемой.
  - `fan` — вентиляция. В этом режиме кондиционер осуществляет только вентиляцию воздуха и не изменяет температуру в комнате.

  Кондиционер достаточно мощный, поэтому при настройке на правильный режим работы он за час доводит температуру в комнате до желаемой.

  Требуется написать программу, которая по заданной температуре в комнате troom, установленным на кондиционере желаемой температуре tcond и режиму работы определяет температуру, которая установится в комнате через час.  
  ——  
  Вам предстоит разработать набор тестов (только входных данных) для этой задачи, тщательно проверяющий решения участников.
  
  **Формат вывода:**  
  Сдавать следует не программу, а текстовый файл. В первой строке файла запишите число N (1 ≤ N ≤ 20) — количество тестов, которые вы разработали. В следующих N строках запишите по одному тесту. Каждый тест должен состоять из чисел troom и tcond (-50 ≤ t_room, t_cond ≤ 50) и режима работы кондиционера (одно из слов freeze, heat, auto, fan).

</details>

### E. Наибольшее произведение двух чисел (составление тестов)

[1_E_TheMaximumProductOfTwoNumbers(Tests).cpp](https://github.com/kateklec/AlgorithmTrainingYandex_6.0_2024/blob/main/AlgorithmTraining_6.0/1_E_TheMaximumProductOfTwoNumbers(Tests).cpp)

<details>
  <summary>Условие задачи</summary>

  **Описание:**  
  На соревновании участникам была предложена следующая задача:
  ——
  Дан список, заполненный произвольными целыми числами. Найдите в этом списке два числа, произведение которых максимально. Выведите эти числа в порядке неубывания. Список содержит не менее двух элементов. Числа подобраны так, что ответ однозначен. Решение должно иметь сложность O(n), где n - размер списка.
  ——
  Вам предстоит разработать набор тестов (только входных данных) для этой задачи, тщательно проверяющий решения участников.

  **Формат вывода**  
  Сдавать следует не программу, а текстовый файл.  
  В первой строке файла запишите число N (1 ≤ N ≤ 20) — количество тестов, которые вы разработали.  
  В следующих N строках запишите по одному тесту. Каждый тест должен состоять из одной строки, в которой записано число K (2 ≤ K ≤ 10) — количество чисел в последовательности, а затем K чисел ai (−100 ≤ ai ≤ 100).

</details>

## Контест 2
### A. Префиксные суммы

[2_A_PrefixSums.cpp](https://github.com/kateklec/AlgorithmTrainingYandex_6.0_2024/blob/main/AlgorithmTraining_6.0/2_A_PrefixSums.cpp)

<details>
  <summary>Условие задачи</summary>
  
  **Описание:**  
  По данной последовательности `a1,a2,...,an` вычислите последовательность ее префиксных сумм `b1,b2,...,bn`, где $b_j = \sum_{i=1}^{j} a_i$.
  
  **Формат ввода**  
  В первой строке дано целое число `n` (1 ≤ n ≤ 10^3)  — количество элементов в последовательности `a`. Во второй строке дано `n` целых чисел `a1,a2,...,an` (∣ai∣ ≤ 10^6)  — элементы последовательности.
  
  **Формат вывода**  
  Выведите `n` целых чисел `b1,b2,...,bn`  — последовательность префиксных сумм для последовательности `a`.

</details>

### B. Сумма номеров

[2_B_SumOfIndices.cpp](https://github.com/kateklec/AlgorithmTrainingYandex_6.0_2024/blob/main/AlgorithmTraining_6.0/2_B_SumOfIndices.cpp)

<details>
  <summary>Условие задачи</summary>
  
  **Описание:**  
  Вася очень любит везде искать своё счастливое число K. Каждый день он ходит в школу по улице, вдоль которой припарковано N машин. Он заинтересовался вопросом, сколько существует наборов машин, стоящих подряд на местах с L до R, что сумма их номеров равна K. Помогите 
  Васе узнать ответ на его вопрос.
  Например, если число N=5, K=17, а номера машин равны 17, 7, 10, 7, 10, то существует 4 набора машин:  
  17 (L = 1,R = 1),
  7, 10 (L = 2,R = 3),
  10, 7 (L = 3,R = 4),
  7, 10 (L = 4,R = 5)
  
  **Формат ввода**  
  В первой строке входных данных задаются числа N и K (1 ≤ N ≤ 100000, 1 ≤ K ≤ 10^9).
  Во второй строке содержится N чисел, задающих номера машин. Номера машин могут принимать значения от 1 до 999 включительно.

  **Формат вывода**  
  Необходимо вывести одно число — количество наборов.
  
</details>

### C. Город Че

[2_C_CityChe.cpp](https://github.com/kateklec/AlgorithmTrainingYandex_6.0_2024/blob/main/AlgorithmTraining_6.0/2_C_CityChe.cpp)

<details>
  <summary>Условие задачи</summary>
  
  **Описание:**  
  В центре города Че есть пешеходная улица - одно из самых популярных мест для прогулок жителей города. По этой улице очень приятно гулять, ведь вдоль улицы расположено n забавных памятников. Девочке Маше из города Че нравятся два мальчика из ее школы, и она никак не может сделать выбор между ними. Чтобы принять окончательное решение, она решила назначить обоим мальчикам свидание в одно и то же время. Маша хочет выбрать два памятника на пешеходной улице, около которых мальчики будут ее ждать. При этом она хочет выбрать такие памятники, чтобы мальчики не увидели друг друга. Маша знает, что из-за тумана мальчики увидят друг друга только в том случае, если они будут на расстоянии не более r метров. Маше заинтересовалась, а сколько способов есть выбрать два различных памятника для организации свиданий.
  
  **Формат ввода**  
  В первой строке входного файла находятся два целых числа n и r (2 ≤ n ≤ 300000, 1 ≤ r ≤ 10^9) - количество памятников и максимальное расстояние, на котором мальчики могут увидеть друг друга.
  Во второй строке задано n положительных чисел d1, ..., dn, где di - расстояние от i-го памятника до начала улицы. Все памятники находятся на разном расстоянии от начала улицы. Памятники приведены в порядке возрастания расстояния от начала улицы (1 ≤ d1, d2, ..., dn ≤ 10^9).

  **Формат вывода**  
  Выведите одно число - число способов выбрать два памятника для организации свиданий.

</details>

### D. Лучший отдых

[2_D_BestRest.cpp](https://github.com/kateklec/AlgorithmTrainingYandex_6.0_2024/blob/main/AlgorithmTraining_6.0/2_D_BestRest.cpp)

<details>
  <summary>Условие задачи</summary>
  
  **Описание:**  
  Васе предстоит выполнить nn дел, для каждого дела он определил направление деятельности, заданное целым числом ai. За один день Вася может сделать любое количество дел, но он считает, что лучший вид отдыха — это смена деятельности. Поэтому он не хочет делать похожие дела в один и тот же день. Дела с номерами ai и aj считаются похожими, если разница между их номерами не превышает заданного коэффициента разнообразия k, то есть если ∣ai−aj∣ ≤ k. Также Вася хочет сделать все свои дела как можно быстрее. Например, если Васе необходимо сделать три дела с направлениями деятельности 1, 2 и 4 при k=2, то в первый день можно сделать дела 1 и 4, а во второй — 2. Сделать все дела за один день нельзя потому что направления деятельности 1 и 2 похожи. Определите минимальное количество дней, необходимое Васе для выполнения всех его дел.

  **Формат ввода**  
  В первой строке ввода через пробел даны два целых числа n и k — количество дел и коэффициент разнообразия (1 ≤ n ≤ 2 * 10^5; 0 ≤ k ≤ 10^9).
  Во второй строке через пробел перечислены nn чисел ai — направления дел (1 ≤ ai ≤ 10^9).

  **Формат вывода**  
  Выведите единственное целое число — минимальное количество дней, необходимое Васе для выполнения всех дел.

</details>

### E. Удаление медиан

[2_E_MedianRemoval.cpp](https://github.com/kateklec/AlgorithmTrainingYandex_6.0_2024/blob/main/AlgorithmTraining_6.0/2_E_MedianRemoval.cpp)

<details>
  <summary>Условие задачи</summary>
  
  **Описание:**  
  Задана последовательность чисел ai длиной n. Из него необходимо последовательно удалять медианы.
  Медиана в этой задаче определяются следующим образом:
  - Если количество чисел в последовательности нечетно, то медиана — число, стоящее точно в середине упорядоченной по возрастанию последовательности.
  - Если количество чисел в последовательности чётно, то медианой последовательности является:

   o Меньшее из двух стоящих посередине чисел упорядоченной по возрастанию последовательности, если два средних различны.  
   o Любое из двух стоящих посередине чисел упорядоченной по возрастанию последовательности, если два средних равны.
  
  Определите в каком порядке будут удалены элементы последовательности.

  **Формат ввода**  
  В первой строке дано одно натуральное число n — количество элементов последовательности (1 ≤ n ≤ 10^5).
  Во второй строке содержатся n натуральных чисел ai — элементы последовательности (1 ≤ ai ≤ 10^9).

  **Формат вывода**  
  Выведите n чисел — порядок удаления чисел из последовательности.

</details>

### F. Сумма тройных произведений

[2_F_SumOfTripleProducts.cpp](https://github.com/kateklec/AlgorithmTrainingYandex_6.0_2024/blob/main/AlgorithmTraining_6.0/2_F_SumOfTripleProducts.cpp)

<details>
  <summary>Условие задачи</summary>
  
  **Описание:**  
  Задана последовательность из nn чисел ai. Найдите число
  $\sum_{1 \leq i < j < k \leq n} a_i \cdot a_j \cdot a_k$
  Поскольку число может получиться слишком большим, требуется посчитать его по модулю 1000000007.

  **Формат ввода**  
  В первой строке дано одно целое число n (3 ≤ n ≤ 10^6).
  Во второй строке даны n целых чисел ai (0 ≤ ai ≤ 10^6).

  **Формат вывода**  
  Выведите требуемое число по модулю 1000000007.

</details>

### G. Цензурное произведение

[2_G_CensoredProduct.cpp](https://github.com/kateklec/AlgorithmTrainingYandex_6.0_2024/blob/main/AlgorithmTraining_6.0/2_G_CensoredProduct.cpp)

<details>
  <summary>Условие задачи</summary>
  
  **Описание:**  
  Комитет по цензуре определил грубость строки t1t2...tk как количество пар индексов (i,j), где 1 ≤ i < j ≤ k, при этом ti = «a», а tj = «b». То есть, грубость строки — это количество способов вычеркнуть из нее буквы так, чтобы осталась строка, состоящая только из двух букв «a» и «b» (именно в этом порядке). Кроме того, по решению того же комитета, все литературные произведения должны представлять собой подстроку определенной комитетом строки s, состоящую из n букв. Вася хочет написать литературное произведение, грубость которого не превосходит c. Для этого он должен выбрать некоторую непустую подстроку строки s, начиная с индекса l и заканчивая индексом r, т.е. состоящую из символов slsl+1...sr. Чем длиннее произведение — тем больше оплата, поэтому Вася хочет, чтобы его произведение было как можно длиннее. Определите длину самого длинного произведения, которое может написать Вася.

  **Формат ввода**  
  Первая строка входных данных содержит два целых числа n и c — длину строки s и максимальную разрешенную грубость литературного произведения (1 ≤ n ≤ 10^6, 0 ≤ c ≤ 10^18).
  Вторая строка содержит строку s. Строка состоит из n строчных английских букв.

  **Формат вывода**  
  Выведите ответ на задачу.
  
</details>

###  H. Переезд в опенспейс*

[2_H_MoveToOpenSpace.cpp](https://github.com/kateklec/AlgorithmTrainingYandex_6.0_2024/blob/main/AlgorithmTraining_6.0/2_H_MoveToOpenSpace.cpp)

<details>
  <summary>Условие задачи</summary>
  
  **Описание:**  
  Сотрудники компании работают в старом советском здании, состоящем из n больших кабинетов, расположенных в один ряд, один за другим. В зале i работает ровно ai сотрудников. HR-менеджеры компании выяснили, что сотрудникам грустно и одиноко в отдельных кабинетах и, чтобы им стало веселее, необходимо переоборудовать один из кабинетов в модный опенспейс и переселить всех сотрудников в него. Переезд сотрудника в другой кабинет сопровождается переносом его рабочего стола, что довольно тяжело и времязатратно. При переезде сотрудник перемещает свой стол по всем кабинетам от своего начального положения до кабинета с опенсейсом. Таким образом, количество переходов сотрудника определяется как модуль разности номеров исходного кабинета и кабинета с оборудованным опенспейсом. HR-менеджеры хотят сделать переезд как можно проще и выбрать такой кабинет для оборудования опенспейса, чтобы минимизировать суммарное количество переходов сотрудников (и их рабочих столов). Помогите им определить это количество переходов.

  **Формат ввода**  
  В первой строке ввода дано целое число n — количество кабинетов в офисе (1 ≤ n ≤ 2 * 10^5).
  В следующей строке через пробел перечислены nn целых чисел ai — количество сотрудников в кабинете i (1 ≤ ai ≤ 10^9).

  **Формат вывода**  
  Выведите одно число — минимальное суммарное количество переходов.

</details>

### I. Изучение алгоритмов*

[2_I_AlgorithmStudy.cpp](https://github.com/kateklec/AlgorithmTrainingYandex_6.0_2024/blob/main/AlgorithmTraining_6.0/2_I_AlgorithmStudy.cpp)

<details>
  <summary>Условие задачи</summary>
  
  **Описание:**  
  Вася готовится к алгоритмической секции собеседования и выяснил, что ему нужно изучить nn алгоритмов. Вася поверхностно изучил каждый из них, и охарактеризовал i-й алгоритм двумя параметрами ai (интересность) и bi (полезность). Вася работает сисадмином на научной базе в Антарктиде и никуда не торопится. Он будет изучать по одному алгоритму в день. Если ему скучно, то он будет изучать самый интересный алгоритм (с максимальным ai) из всех еще не изученных. А если у него воодушевленное настроение, то выберет для изучения самый полезный алгоритм из еще не изученных (с максимальным bi). Если есть несколько алгоритмов с максимальным интересующим Васю параметром, то он выберет тот, у которого второй параметр наибольший. Если и вторые параметры равны, то Вася выберет алгоритм с меньшим порядковым номером. Вася — предсказуемый человек (и гордится этим), поэтому он знает свое настроение на nn дней вперед. Определите, в каком порядке он изучит алгоритмы.

  **Формат ввода**  
  В первой строке ввода дано целое число n — количество алгоритмов (1 ≤ n ≤ 10^5).
  Во второй строке через пробел перечислены n целых чисел ai — значения интересности алгоритмов (1 ≤ ai ≤ 10^9). В третьей строке в том же формате даны целые числа bi — значения полезности алгоритмов (1 ≤ bi ≤ 10^9).
  В последней строке через пробел перечислены nn целых чисел pi — индикаторы настроения Васи в ближайшие n дней. Если pi = 1, Вася выберет алгоритм с максимальной полезностью (максимальным bi), иначе pi = 0 и Вася выберет самый интересный из доступных алгоритмов (с максимальным ai).

  **Формат вывода**  
  Выведите n различных целых чисел от 1 до n, разделенных пробелами; i-е число должно быть равно номеру алгоритма, который Вася будет изучать в i-й день.

</details>

### J. Исследование улик*

[2_J_EvidenceInvestigation.cpp](https://github.com/kateklec/AlgorithmTrainingYandex_6.0_2024/blob/main/AlgorithmTraining_6.0/2_J_EvidenceInvestigation.cpp)

<details>
  <summary>Условие задачи</summary>
  
  **Описание:**  
  Бенуа Бланк взялся за расследование загадочного преступления и теперь активно ищет улики, которые помогут ему выйти на настоящего преступника. Как любой уважающий себя детектив, Бенуа Бланк имеет собственный метод поиска истины. Как он любит повторять, его философия заключается в том, что можно просто быть пассивным наблюдателем, и жизнь сама выведет тебя к правде. Всего Бенуа Бланк собрал n улик и расположил перед собой в ряд, i-я улика в ряду имеет весомость, равную ai. Детектив считает, что наиболее интересными могут оказаться наименее весомые улики, и разработал следующий процесс их исследования. Сперва Бланк выбирает какую-то улику с номером x и начинает перебирать улики слева от нее. Пока слева от текущей улики находится улика меньшей или равной весомости, Бенуа Бланк перемещается к ней. При этом, эксцентричному детективу быстро надоедает однообразие, поэтому он не будет делать больше k перемещений между уликами с одинаковой весомостью.

  Например, если весомости улик равны ⟨3,3,3,4,4,5⟩, k=2, и детектив начинает с последней улики, он совершит четыре перемещения влево, после чего остановится. Улики требуют тщательного изучения, поэтому Бенуа Бланк повторяет процесс m раз, в i-й раз начиная с улики с номером xi. Помогите ему побыстрее определить, на какой улике он остановится в каждом из случаев.

  **Формат ввода**  
  В первой строке дано целое число n — количество улик (1 ≤ n ≤ 4 * 10^5). Во второй строке через пробел перечислены nn целых чисел ai — значения весомости улик в порядке их следования в ряду (1 ≤ ai ≤ 10^9).
  В следующей строке через пробел даны два целых числа m и k — количество экспериментов и максимальное число перемещений между уликами равной весомости (1 ≤ m ≤ 4 * 10^5; 0 ≤ k ≤ n).
  В последней строке через пробел перечислены m целых чисел xi — номера улик, с которых Бенуа Бланк будет начинать исследование (1 ≤ xi ≤ n).

  **Формат вывода**  
  Выведите через пробел m целых чисел от 1 до n — номера улик, на которых остановится детектив в каждом из экспериментов.

</details>
