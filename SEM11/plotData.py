import osmnx as ox
import matplotlib.pyplot as plt

place = "Barranco, Lima"
G = ox.graph_from_place(place, network_type = "drive")
print(type(G))
#ox.plot_graph(G, node_color = "red")
fig, ax = ox.plot_graph(G, node_color = "red", show=False, close=False)

file = open("data.txt", "w")
for row in  G.edges(data = True):
    print(row)
    u = row[0]
    v = row[1]
    w = row[2]['length']
    file.write(str(u) + " " + str(v) + " " + str(w) + "\n")
file.close()


u = 197654185
v = 3672931645


# 4. Dibujar una línea roja entre u y v (si hay geometría disponible)
edge_data = G.get_edge_data(u, v, default=None)
if edge_data:
    # Algunos grafos tienen múltiples edges entre u y v
    edge = list(edge_data.values())[0]

    if 'geometry' in edge:
        print(edge['geometry'])
        xs, ys = edge['geometry'].xy
        print(xs, ys)
        ax.plot(xs, ys, color='blue', linewidth=4, label=f'{u}→{v}')
    else:
        # Si no hay geometría, usar coordenadas de los nodos
        x0, y0 = G.nodes[u]['x'], G.nodes[u]['y']
        x1, y1 = G.nodes[v]['x'], G.nodes[v]['y']
        ax.plot([x0, x1], [y0, y1], color='blue', linewidth=4, label=f'{u}→{v}')

plt.legend()
plt.show()