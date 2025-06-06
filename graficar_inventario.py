import pandas as pd
import matplotlib.pyplot as plt

# Leer CSV
df = pd.read_csv("reporte_inventario.csv")

# Opcional: Verificar contenido
print("\nContenido del inventario:\n", df)

# Crear columna de faltantes
df["Faltante"] = df["CantidadRequerida"] - df["Cantidad"]

# Gráfica 1: Stock actual vs requerido
plt.figure(figsize=(10, 6))
df.plot(kind="bar", x="Nombre", y=["Cantidad", "CantidadRequerida"])
plt.title("Stock actual vs requerido")
plt.ylabel("Cantidad")
plt.xticks(rotation=45)
plt.tight_layout()
plt.show()

# Gráfica 2: Productos con faltantes
productos_faltantes = df[df["Faltante"] > 0]

plt.figure(figsize=(10, 6))
plt.bar(productos_faltantes["Nombre"], productos_faltantes["Faltante"])
plt.title("Productos con faltante")
plt.ylabel("Unidades necesarias")
plt.xticks(rotation=45)
plt.tight_layout()
plt.show()
