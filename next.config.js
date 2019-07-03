const withTM = require('next-transpile-modules');
const bsConfig = require('./bsconfig.json');

module.exports = withTM({
  transpileModules: [...bsConfig['bs-dependencies'], 'bs-platform'],
  pageExtensions: ['jsx', 'js', 'bs.js'],
});
