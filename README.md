# Velocifare

Velocifare is an experimental C framework aiming to empower web developers to build faster and more secure static websites. It works by compiling all the web site's source code into a single binary executable, bundled along with a lightweight web server. The goal is to enhance the speed and efficiency of web applications, making them more scalable and cost-effective.

## Features

- **Efficiency:** By compiling the website into a single binary executable, Velocifare aims to reduce overhead and enhance performance.
- **Minimalism:** The framework is designed with minimalism in mind, providing only the essential features needed for building static websites.
- **Speed:** With a focus on speed, Velocifare enables rapid development and deployment of web applications.
- **Integration:** Developers can integrate their favorite front-end JavaScript frameworks, as long as they pre-render all their code. The compiler seamlessly includes them into the web server itself.
- **Demo:** Check out our demo site, showcasing a pre-rendered Svelte app.

## Getting Started

To get started with Velocifare, follow these steps:

1. Clone the repository: `git clone https://github.com/TheJostler/velocifare`
2. Navigate to the project directory: `cd velocifare/dev`
3. Install node packages for the demo app with: `npm install`
4. Navigate back to the parent directory: `cd ..`
5. Build the project using the provided MakeFile: `make build`/ `make rebuild` to force a rebuild
6. Run the compiled binary executable: `./velocifare`

## Usage

Velocifare follows a simple workflow:

1. **Development:** Build your static website using your preferred front-end frameworks.
2. **Pre-rendering:** Ensure all code is pre-rendered to enable seamless integration with the framework.
3. **Compilation:** Compile your website into a single binary executable using Velocifare.
4. **Deployment:** Deploy the compiled executable along with the bundled web server to your hosting environment.

## Contributing

Contributions are welcome! If you'd like to contribute to Velocifare, please follow these guidelines:

- Fork the repository
- Create a new branch for your feature or fix: `git checkout -b feature-name`
- Make your changes and commit them: `git commit -am 'Add new feature'`
- Push to your fork: `git push origin feature-name`
- Submit a pull request

## License

This project is licensed under the GNU General Public Licence - see the [LICENSE](LICENSE) file for details.

## Acknowledgements

- Inspired by the need for speed and efficiency in web development.
- Special thanks to the Svelte team for providing a powerful pre-rendering solution.

---
