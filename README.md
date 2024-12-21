# SkyNav: A Global Flight and Landmark Navigator

### Overview

SkyNav is a comprehensive tool designed to assist global travelers in navigating air routes and discovering nearby points of interest. Whether you’re seeking the closest airport to your current coordinates or planning the shortest possible flight itinerary between two distant airports, SkyNav’s integrated algorithms help streamline your journey. Additionally, SkyNav provides insights into popular sightseeing spots near your destination, making it easier than ever to plan an enriched travel experience.

### Core Algorithms and Their Functionality

1. **BFS-Find (Nearest Airport Locator)**  
   - **Goal:** Identify the closest airport to a given geographic coordinate (latitude and longitude).
   - **Description:**  
     This component takes a user’s current position and employs a Breadth-First Search (BFS) across a spatial graph of airports. By starting at the given coordinates and “expanding” outward, the BFS quickly finds the nearest airport node reachable from that point.
   - **Output:**  
     The algorithm returns the coordinates and identifying information of the airport that is geographically closest to the user’s specified location.

2. **Dijkstra’s (Shortest Air Route Planner)**  
   - **Goal:** Compute the shortest possible path between two airports.
   - **Description:**  
     Using Dijkstra’s algorithm, SkyNav considers each airport as a node in a weighted graph, with routes between airports as edges and flight distance as edge weights. By taking in both an origin and a destination coordinate, this algorithm efficiently determines the shortest sequence of connecting flights.
   - **Output:**  
     A step-by-step itinerary, showing the sequence of airports that form the optimal route from the start to the destination, minimizing total travel distance.

3. **PageRank-Based Landmark Ranking (Proximity Sorter)**  
   - **Goal:** Rank a set of global sightseeing locations according to their proximity and relevance to a specified destination airport.
   - **Description:**  
     After identifying the user’s destination, SkyNav leverages a PageRank-inspired method to sort selected landmarks. While PageRank traditionally ranks web pages based on link structure, here we adapt the concept to geographical “connections.” In conjunction with spatial data, this produces a weighted ranking that favors landmarks closer to the chosen airport, ensuring that the returned list is both relevant and practical for travelers.
   - **Output:**  
     A sorted list of 15-20 recommended attractions, ordered by their relative closeness to the destination airport.

### Project Goals and Guiding Questions

**Primary Questions:**

1. **Nearest Airport Discovery:** Can we find the nearest airport given an individual’s current latitude and longitude coordinates?
2. **Optimal Route Calculation:** How can we determine the shortest flight path between any two airports across the globe?

**Approach:**

- **For Nearest Airport (BFS-Find):**  
  By accepting user coordinates as input, our BFS-based algorithm scans through the global network of airports. Instead of brute forcing through all data, BFS ensures an efficient, structured search that quickly identifies the closest node. This can guide travelers who need to determine the best departure or arrival point from their current location.

- **For Shortest Path (Dijkstra’s):**  
  Given a known origin and destination airport, Dijkstra’s algorithm calculates the shortest viable route. This includes understanding flight connections and the relative distances between airports. The method ensures the output is not just a direct link (if it exists) but a full sequence of segments that yield the minimum cumulative travel distance.

**Additional Landmarks Insight:**

The adapted PageRank-like algorithm goes beyond standard flight planning. After the primary route is set, travelers often want to explore. By incorporating a ranking system that weights sightseeing spots relative to their destination, SkyNav helps users effortlessly plan their post-flight adventures, ensuring they can make the most of every journey.

---

By integrating these three major algorithms—BFS for nearest airports, Dijkstra’s for shortest routes, and PageRank-inspired sorting for landmarks—SkyNav provides a holistic travel assistant. It not only answers the essential navigational questions but also enriches the travel experience through intelligent recommendation of points of interest.
