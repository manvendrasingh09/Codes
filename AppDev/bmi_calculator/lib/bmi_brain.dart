import 'dart:math';

class BMIBrain {
  BMIBrain({required this.height, required this.weight});
  final int height;
  final int weight;

  late double _bmi;

  String calBMI() {
    _bmi = weight / pow(height / 100, 2);
    return _bmi.toStringAsFixed(1);
  }

  String getResult() {
    if (_bmi >= 25) {
      return 'Overweight';
    } else if (_bmi > 18.5) {
      return 'Normal';
    } else {
      return 'Underweight';
    }
  }

  String getInterpretation() {
    if (_bmi >= 25) {
      return 'You have a higher weight than normal body weight. \nTry to exercise more.';
    } else if (_bmi > 18.5) {
      return 'You have a normal body weight. \nGood Job!';
    } else {
      return 'You have a lower weight than normal body weight. \nIncrease your diet.';
    }
  }
}
