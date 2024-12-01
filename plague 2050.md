Topic : Plague 2050

Problem Description

In the year 2050, a plague outbreak has impacted a state, spreading rapidly, and becoming increasingly contagious. A team of doctors is on a mission to obtain a crucial herb that is located only in a particular part of the state.

The state is structured as a square grid of size N, consisting of N×N cities, each occupying an area of 1 unit and with each city having 8 neighbouring cities, except for those located along the boundaries of grid. These cities are categorized as either infected or uninfected, represented by 1 and 0, respectively. The plague spreads based on specific conditions given below.

1. If a city is uninfected and has exactly three neighbouring cities that are infected, the plague will spread to that city, causing it to become infected the following day.

2. Any infected city with two or three neighbouring infected cities will remain infected the following day.

3. Any infected city with less than two neighbouring infected cities will become uninfected the next day, due to reduced transmission of the infection.

4. Any infected city with more than three neighboring infected cities will become uninfected the next day, due to increased medical attention from the government.

5. A team of doctors is working to find a permanent cure for the plague and needs to prepare medicine from an herb that is only available in a specific city.

Each day, the team of doctors faces two options:

1. They can either stay in their current city or move to an adjacent city.

2. As the plague spreads, they receive daily reports on the status of infected and non-infected cities, allowing them to predict the conditions for the following day.

3. They plan to travel to cities that will be uninfected the next day and avoid staying in cities that are expected to become infected.

4. Given the doctor's team's starting city represented as "s," the city where the herb can be found as "d," and today's report on city statuses, assist them in determining the minimum number of days required to reach the city with the herb if they move optimally. They can travel to only one city in one day.

Constraints
3 <= N <= 7

The city having herbs is always reachable.

From a given city, even if there is chance of moving to another city, doctors can choose to stay in the same city without moving. Doctors will never stay in the current city if it is going to be infected the next day.

Input
First line contains an integer N representing the size of the state.

The next N lines contain N space-separated values, which can be either "s," "d," "0," or "1." Here, "0" indicates an uninfected city, "1" indicates an infected city, "s" represents the source (the city of the doctors' team), and "d" signifies the destination (the city where the herb is located). Both the "s" and "d" cities are considered uninfected in the Day 1 report.

Output
Single integer representing the minimum number of days required to travel to the city having the herbs used for medicine.

Time Limit (secs)
1

Examples
Example 1

Input
4
s 0 1 1
1 1 0 0
1 1 0 d
0 0 1 1

Output
8

Explanation

1. The state grid consists of 16-cities in a 4x4 representation. Top left is (0, 0) and bottom right is (3, 3). From the input we know that the coordinates (0, 0) represent the city where the doctors are currently located, while (2, 3) indicates the location of the city where the herb can be found.

2. From the given report of day 1, considering the neighbours of (0,0), it has 2 infected and 1 uninfected city.

3. According to the given rules, a city will become infected when three of its neighbouring cities are infected. So, it remains uninfected for the next day.

4. Considering the neighbours of (0,1) there are 3 infected and 2 uninfected cities. When an uninfected city has three infected neighbours it becomes infected. So (0,1) will become infected for next day.

5. By applying given logics to every city, we predict report for upcoming days which will look like above.

6. Up to day4 the report has been predicted, the report will stay same after day four. Up to day 3 doctors must stay in (0,0).

7. After day 3 they follow the path (0,1), (0,2), (0,3), (1,3) and (2,3).
   On day 8 they will reach the city where the herb is located. It is not possible to reach the destination city within less than 8 days. Hence print 8 as output.

Example 2

Input
5
s 0 0 0 0
0 0 0 d 0
0 0 1 1 0
0 1 1 0 0
0 0 1 0 0

Output
6

Explanation

1. The state grid consists of 25-cities in a 5x5 representation. Top left is (0, 0) and bottom right is (4, 4). The coordinates (0, 0) represent the city where the doctors are currently located, while (1, 3) indicates the location of the city where the herb can be found.

2. The destination city can be reached directly on day 5, but it will be infected by that day. Therefore, the doctors need to remain in another city for an additional day and can then travel to the destination city (1, 3) on day 6. Hence print 6 as output.
