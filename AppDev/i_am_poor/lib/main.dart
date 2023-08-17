import 'package:flutter/material.dart';

void main() {
  runApp(
    MaterialApp(
      home: Scaffold(
        backgroundColor: Colors.brown[400],
        body: const Center(
          child: Image(
            image: AssetImage('images/poor.jpg'),
          ),
        ),
        appBar: AppBar(
          title: const Text('I Am Poor'),
          backgroundColor: Colors.brown,
        ),
      ),
    ),
  );
}
