import 'package:audioplayers/audioplayers.dart';
import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  void playSound(int a) {
    final player = AudioPlayer();
    player.setSource(
      AssetSource('note$a.wav'),
    );
    player.resume();
  }

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        body: SafeArea(
          child: Column(
            children: [
              MaterialButton(
                color: Colors.red,
                onPressed: () {
                  playSound(1);
                },
              ),
              MaterialButton(
                color: Colors.blue,
                onPressed: () {
                  playSound(2);
                },
              ),
              MaterialButton(
                color: Colors.green,
                onPressed: () {
                  playSound(3);
                },
              ),
              MaterialButton(
                color: Colors.yellow,
                onPressed: () {
                  playSound(4);
                },
              ),
              MaterialButton(
                color: Colors.orange,
                onPressed: () {
                  playSound(5);
                },
              ),
              MaterialButton(
                color: Colors.purple,
                onPressed: () {
                  playSound(6);
                },
              ),
              MaterialButton(
                color: Colors.brown,
                onPressed: () {
                  playSound(7);
                },
              ),
            ],
          ),
        ),
      ),
    );
  }
}
