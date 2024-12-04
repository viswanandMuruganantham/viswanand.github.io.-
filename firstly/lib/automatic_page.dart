import 'package:flutter/material.dart';

class AutomaticPage extends StatelessWidget {
  const AutomaticPage({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Automatic Page'),
      ),
      body: Padding(
        padding: const EdgeInsets.all(16.0),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: <Widget>[
            // Profile name (you can adjust this to be more relevant for the Automatic page if needed)
            const Text(
              'Automatic Control',
              style: TextStyle(
                fontSize: 24,
                fontWeight: FontWeight.bold,
              ),
            ),
            const SizedBox(height: 20), // Space between title and boxes

            // Grid of four boxes
            Expanded(
              child: GridView.builder(
                gridDelegate: const SliverGridDelegateWithFixedCrossAxisCount(
                  crossAxisCount: 2,
                  crossAxisSpacing: 16,
                  mainAxisSpacing: 16,
                ),
                itemCount: 4,
                itemBuilder: (BuildContext context, int index) {
                  final boxContent = [
                    {'title': 'Auto Soil Moister', 'value': '100'},
                    {'title': 'Auto Temperature', 'value': '30°C'},
                    {'title': 'Auto Water Quality', 'value': '60'},
                    {'title': 'Auto Water PH', 'value': '8'},
                  ];
                  return Container(
                    alignment: Alignment.center,
                    color: Colors.blueAccent,
                    child: Column(
                      mainAxisAlignment: MainAxisAlignment.center,
                      children: [
                        Text(
                          boxContent[index]['title']!,
                          style: const TextStyle(
                            color: Colors.white,
                            fontSize: 16,
                            fontWeight: FontWeight.bold,
                          ),
                        ),
                        const SizedBox(height: 8),
                        Text(
                          boxContent[index]['value']!,
                          style: const TextStyle(
                            color: Colors.white,
                            fontSize: 24,
                            fontWeight: FontWeight.bold,
                          ),
                        ),
                      ],
                    ),
                  );
                },
              ),
            ),
          ],
        ),
      ),
    );
  }
}
