# SiteInC

SiteInC is an experimental C framework aiming to empower web developers to build static websites and compile them into a single binary executable, bundled along with a lightweight web server. The goal is to enhance the speed and efficiency of web applications, making them more scalable and cost-effective.

## Features

- **Efficiency:** By compiling the website into a single binary executable, SiteInC aims to reduce overhead and enhance performance.
- **Minimalism:** The framework is designed with minimalism in mind, providing only the essential features needed for building static websites.
- **Speed:** With a focus on speed, SiteInC enables rapid development and deployment of web applications.
- **Integration:** Developers can integrate their favorite front-end JavaScript frameworks, as long as they pre-render all their code. The compiler seamlessly includes them into the web server itself.
- **Demo:** Check out our demo site, showcasing a pre-rendered Svelte app.

## Getting Started

To get started with SiteInC, follow these steps:

1. Clone the repository: `git clone https://github.com/TheJostler/siteinc`
2. Navigate to the project directory: `cd siteinc`
3. Build the project using the provided build script: `./build.sh`
4. Run the compiled binary executable: `./sic`

## Usage

SiteInC follows a simple workflow:

1. **Development:** Build your static website using your preferred front-end frameworks.
2. **Pre-rendering:** Ensure all code is pre-rendered to enable seamless integration with the framework.
3. **Compilation:** Compile your website into a single binary executable using SiteInC.
4. **Deployment:** Deploy the compiled executable along with the bundled web server to your hosting environment.

## Contributing

Contributions are welcome! If you'd like to contribute to SiteInC, please follow these guidelines:

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
