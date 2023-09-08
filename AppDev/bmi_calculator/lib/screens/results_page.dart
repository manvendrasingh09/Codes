import 'package:flutter/material.dart';
import 'constants.dart';
import 'reusable_card.dart';
import 'bottom_button.dart';

class ResultsPage extends StatelessWidget {
  const ResultsPage({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('BMI Calculator'),
      ),
      body: Column(
        mainAxisAlignment: MainAxisAlignment.spaceEvenly,
        crossAxisAlignment: CrossAxisAlignment.stretch,
        children: [
          Expanded(
            child: Container(
              child: const Text(
                'Your Result',
                style: kTitle,
              ),
            ),
          ),
          const Expanded(
            flex: 5,
            child: ReusableCard(
              colour: kActiveCardColour,
              cardChild: Column(
                mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                crossAxisAlignment: CrossAxisAlignment.center,
                children: [
                  Text(
                    'Result',
                    style: kResultText,
                  ),
                  Text(
                    '18.0',
                    style: kBMI,
                  ),
                  Text(
                    'Your BMI Result is low, you should eat more',
                    textAlign: TextAlign.center,
                    style: kBMIBody,
                  )
                ],
              ),
            ),
          ),
          BottomButton(
            bText: 'RE-CALCULATE',
            onTap: () {},
          )
        ],
      ),
    );
  }
}
