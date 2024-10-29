% Define the parameters
Fs = 40 * pi; % Sampling frequency (Hz)
Ts = 1 / Fs; % Sampling period
L = 7; % Quantization levels

% Define the time vector for the analog signal
t = 0:Ts:1;

% Generate the analog signal
x = 2 * cos(20 * pi * t);

% Generate the sampled signal
n = 0:1:length(t)-1;
x_sampled = 2 * cos(20 * pi * n * Ts);

% Generate the quantized levels
quant_levels = linspace(-2, 2, L);%% give delta

% Quantize the sampled signal
x_quantized = zeros(size(x_sampled));
for i = 1:length(x_sampled)
    [~, index] = min(abs(x_sampled(i) - quant_levels));
    x_quan  tized(i) = quant_levels(index);
end

% Plot the signals
subplot(3, 1, 1);
plot(t, x);
title('Analog Signal');
xlabel('Time (s)');
ylabel('Amplitude');

subplot(3, 1, 2);
stem(n*Ts, x_sampled);
title('Sampled Signal');
xlabel('Time (s)');
ylabel('Amplitude');

subplot(3, 1, 3);
stem(n*Ts, x_quantized);
title('Quantized Signal (L=7)');
xlabel('Time (s)');
ylabel('Amplitude');