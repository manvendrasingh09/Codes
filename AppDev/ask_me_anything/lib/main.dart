import 'package:flutter/material.dart';
import 'dart:math';

void main() {
  return runApp(
    MaterialApp(
      home: Scaffold(
        backgroundColor: Colors.blue,
        appBar: AppBar(
          title: const Text('Ask Me Anything'),
          backgroundColor: Colors.blue[900],
        ),
        body: const Ama(),
      ),
    ),
  );
}

class Ama extends StatefulWidget {
  const Ama({super.key});

  @override
  State<Ama> createState() => _AmaState();
}

class _AmaState extends State<Ama> {
  int change = 5;
  @override
  Widget build(BuildContext context) {
    return Row(
      children: [
        Expanded(
          child: Center(
            child: TextButton(
              onPressed: () {
                setState(() {
                  change = Random().nextInt(5) + 1;
                });
              },
              child: Image.asset('images/ball$change.png'),
            ),
          ),
        ),
      ],
    );
  }
}
