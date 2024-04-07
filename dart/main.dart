class Product {
  final String productName;
  final String productImagePath;
  final int proudctID;
  final String productDescripton;

  Product(this.productName, this.productImagePath, this.proudctID,
      this.productDescripton);
}

void main() {
  Map<String, dynamic> test = {
    'id': 1,
  };

  print(test['id']);
}
